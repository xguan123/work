#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "cpp_pubsub/msg/signal.hpp"
#include "std_msgs/msg/float64.hpp"

using std::placeholders::_1;

class SignalProcessor : public rclcpp::Node
{
public:
    SignalProcessor()
    : Node("signal_processor")
    {
        subscription_ = this->create_subscription<cpp_pubsub::msg::Signal>(
            "raw_signals", 10, std::bind(&SignalProcessor::signal_callback, this, _1));

        processed_publisher_ = this->create_publisher<std_msgs::msg::Float64>("processed_signal", 10);

        sine_publisher_ = this->create_publisher<std_msgs::msg::Float64>("sine_wave", 10);

        square_publisher_ = this->create_publisher<std_msgs::msg::Float64>("square_wave", 10);
    }

private:
    void signal_callback(const cpp_pubsub::msg::Signal::SharedPtr msg) const
    {
        // 处理信号
        double processed = (msg->sine_wave * msg->square_wave >= 0) ? msg->sine_wave : 0.0;
        
        // 发布处理后的信号
        auto processed_msg = std_msgs::msg::Float64();
        processed_msg.data = processed;
        processed_publisher_->publish(processed_msg);
        
        // 发布原始正弦波用于可视化
        auto sine_msg = std_msgs::msg::Float64();
        sine_msg.data = msg->sine_wave;
        sine_publisher_->publish(sine_msg);
        
        // 发布方波用于可视化
        auto square_msg = std_msgs::msg::Float64();
        square_msg.data = msg->square_wave;
        square_publisher_->publish(square_msg);
        
        static size_t count = 0;
        if (count++ % 100 == 0) {
            RCLCPP_INFO(this->get_logger(), "Processed: %.2f (Sine: %.2f, Square: %.2f)",
                      processed, msg->sine_wave, msg->square_wave);
        }
    }
    
    rclcpp::Subscription<cpp_pubsub::msg::Signal>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr processed_publisher_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr sine_publisher_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr square_publisher_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SignalProcessor>());
    rclcpp::shutdown();
    return 0;
}
