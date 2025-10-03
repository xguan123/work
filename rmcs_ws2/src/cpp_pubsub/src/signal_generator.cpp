#include <chrono>
#include <functional>
#include <memory>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "cpp_pubsub/msg/signal.hpp"

using namespace std::chrono_literals;

class SignalGenerator : public rclcpp::Node
{
public:
    SignalGenerator()
    : Node("signal_generator"), count_(0)
    {
        // 创建发布者，发布频率为1000Hz
        publisher_ = this->create_publisher<cpp_pubsub::msg::Signal>("raw_signals", 10);
        
        // 设置定时器，1ms触发一次，实现1000Hz的发布频率
        timer_ = this->create_wall_timer(
            1ms, std::bind(&SignalGenerator::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto message = cpp_pubsub::msg::Signal();
        
        // 计算时间（秒）
        double time = count_ * 0.001;  // 因为1ms触发一次
        
        // 生成10Hz的正弦波 (sin(2πft))
        message.sine_wave = std::sin(2 * M_PI * 10 * time);
        
        // 生成1Hz的方波 (周期1秒，高低电平各0.5秒)
        // 当sin(2π*1*time) >= 0时为1.0，否则为-1.0
        message.square_wave = std::sin(2 * M_PI * 1 * time) >= 0 ? 1.0 : -1.0;
        
        // 每100次发布打印一次信息（大约10Hz的打印频率）
        if (count_ % 100 == 0) {
            RCLCPP_INFO(this->get_logger(), "Publishing - Sine: %.2f, Square: %.2f",
                      message.sine_wave, message.square_wave);
        }
        
        publisher_->publish(message);
        count_++;
    }
    
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<cpp_pubsub::msg::Signal>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SignalGenerator>());
    rclcpp::shutdown();
    return 0;
}
