#include <chrono>
#include <functional>
#include <memory>
#include <cmath>
#include <cstdlib>  
#include <ctime>   

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

using namespace std::chrono_literals;

class NoiseGenerator2 : public rclcpp::Node
{
public:
  NoiseGenerator2()
  : Node("noise_generator2"), 
    count_(0)
  {

    srand((unsigned int)time(NULL));

    publisher_ = this->create_publisher<std_msgs::msg::Float64>("raw_multi_freq_data", 20);


    timer_ = this->create_wall_timer(
      1ms, std::bind(&NoiseGenerator2::timer_callback, this));

    RCLCPP_INFO(this->get_logger(), "noise_generator2");
  }

private:
  void timer_callback()
  {
    double current_time = count_ * 0.001;

    double useful_signal = std::sin(2 * M_PI * 50 * current_time);   
    double high_freq_noise = 0.3 * std::sin(2 * M_PI * 300 * current_time); 
    double random_noise = ((double)rand() / RAND_MAX) * 0.5 - 0.25;  

    double mixed_data = useful_signal + high_freq_noise + random_noise;

    auto msg = std_msgs::msg::Float64();
    msg.data = mixed_data;
    publisher_->publish(msg);

    if (count_ % 100 == 0) {
      RCLCPP_INFO(this->get_logger(), 
                  "混合数据：%.3f | 有用信号：%.3f | 高频干扰：%.3f",
                  mixed_data, useful_signal, high_freq_noise);
    }

    count_++;
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<NoiseGenerator2>());
  rclcpp::shutdown();
  return 0;
}