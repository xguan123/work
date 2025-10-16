#include <memory>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

using std::placeholders::_1;

class LowpassNode : public rclcpp::Node
{
public:
  LowpassNode()
  : Node("lowpass_node"),
    alpha_(1.0 / (1.0 + 1.0/(2 * M_PI * 250.0 * 0.001))),
    last_filtered_(0.0),
    is_first_data_(true)
  {
    RCLCPP_INFO(this->get_logger(), "低通节点（lowpass_node）启动：截止频率250Hz，alpha=%.3f", alpha_);
    subscriber_ = this->create_subscription<std_msgs::msg::Float64>(
      "raw_multi_freq_data", 20, 
      std::bind(&LowpassNode::data_callback, this, _1));

    filtered_pub_ = this->create_publisher<std_msgs::msg::Float64>("lowpass_filtered_data", 20);
    raw_pub_ = this->create_publisher<std_msgs::msg::Float64>("visual_raw_data", 20);
  }

private:
  void data_callback(const std_msgs::msg::Float64::SharedPtr msg) const
  {
    double raw_data = msg->data;
    auto& last_filtered = const_cast<double&>(last_filtered_);
    auto& is_first_data = const_cast<bool&>(is_first_data_);
    double filtered_data;

    if (is_first_data) {
      filtered_data = raw_data;
      last_filtered = filtered_data;
      is_first_data = false;
    } else {
      filtered_data = alpha_ * raw_data + (1 - alpha_) * last_filtered;
      last_filtered = filtered_data;
    }

    auto filtered_msg = std_msgs::msg::Float64();
    filtered_msg.data = filtered_data;
    filtered_pub_->publish(filtered_msg);

    auto raw_msg = std_msgs::msg::Float64();
    raw_msg.data = raw_data;
    raw_pub_->publish(raw_msg);

    static size_t print_count = 0;
    if (print_count++ % 100 == 0) {
      RCLCPP_INFO(this->get_logger(), 
                  "原始数据：%.3f → 滤波后：%.3f",
                  raw_data, filtered_data);
    }
  }

  rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr subscriber_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr filtered_pub_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr raw_pub_;
  const double alpha_;           
  mutable double last_filtered_;  
  mutable bool is_first_data_;     
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LowpassNode>());
  rclcpp::shutdown();
  return 0;
}