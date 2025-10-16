#include <memory>
#include <vector>
#include <algorithm>  
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
using std::placeholders::_1;  


class MidFilterNode : public rclcpp::Node
{
public:
  MidFilterNode()
  : Node("mid_filter_node"),  
    window_size_(5),          
    data_window_()           
  {
    subscriber_ = this->create_subscription<std_msgs::msg::Float64>(
      "raw_noisy_data", 10, 
      std::bind(&MidFilterNode::data_callback, this, _1));

    filtered_pub_ = this->create_publisher<std_msgs::msg::Float64>("filtered_data", 10);

    raw_pub_ = this->create_publisher<std_msgs::msg::Float64>("raw_data_visual", 10);

    RCLCPP_INFO(this->get_logger(), "中值滤波节点（窗口大小：%d）", window_size_);
  }

private:
  void data_callback(const std_msgs::msg::Float64::SharedPtr msg) const
  {
    double raw_data = msg->data;

    auto& window = const_cast<std::vector<double>&>(data_window_); 
    window.push_back(raw_data);  
    if (window.size() > window_size_) {
      window.erase(window.begin());  
    }

    if (window.size() == window_size_) {
      std::vector<double> sorted_window = window;
      std::sort(sorted_window.begin(), sorted_window.end());  

      double median = sorted_window[window_size_ / 2];  

      auto filtered_msg = std_msgs::msg::Float64();
      filtered_msg.data = median;
      filtered_pub_->publish(filtered_msg);

      auto raw_msg = std_msgs::msg::Float64();
      raw_msg.data = raw_data;
      raw_pub_->publish(raw_msg);

      static size_t print_count = 0;
      if (print_count++ % 10 == 0) {
        RCLCPP_INFO(this->get_logger(), 
                    "原始数据：%.3f → 滤波后：%.3f",
                    raw_data, median);
      }
    } 
  }

  rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr subscriber_;  
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr filtered_pub_;   
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr raw_pub_;   
  const int window_size_;  
  mutable std::vector<double> data_window_;  
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MidFilterNode>());
  rclcpp::shutdown();
  return 0;
}