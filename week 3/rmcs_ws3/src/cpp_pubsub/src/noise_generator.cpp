#include <chrono>
#include <functional>
#include <memory>
#include <cmath>
#include <random>  
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp" 
#include <ctime>
#include <cstdlib>
using namespace std::chrono_literals;

class NoiseGenerator : public rclcpp::Node
{
public:
  NoiseGenerator()
  : Node("noise_generator"), 
    count_(0)
  {
  
    srand((unsigned int)time(NULL));  
    publisher_ = this->create_publisher<std_msgs::msg::Float64>("raw_noisy_data", 10);

    timer_ = this->create_wall_timer(
      20ms, std::bind(&NoiseGenerator::timer_callback, this));

    RCLCPP_INFO(this->get_logger(), "Noise Generator ");
  }

private:
  void timer_callback()
  {
    double current_time = count_ * 0.02;
    double sine_wave = std::sin(2 * M_PI * 1 * current_time);
    double noise = ((double)rand() / RAND_MAX) * 2 - 1;
    double noisy_data = sine_wave + noise;
    auto msg = std_msgs::msg::Float64();
    msg.data = noisy_data;
    publisher_->publish(msg);

    if (count_ % 10 == 0) {
      RCLCPP_INFO(this->get_logger(), 
                  "生成数据：%.3f | 信号：%.3f | 噪声：%.3f",
                  noisy_data, sine_wave, noise);
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
  rclcpp::spin(std::make_shared<NoiseGenerator>());  
  rclcpp::shutdown();  
  return 0;
}