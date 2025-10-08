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
        publisher_ = this->create_publisher<cpp_pubsub::msg::Signal>("raw_signals", 10);
        
        timer_ = this->create_wall_timer(
            1ms, std::bind(&SignalGenerator::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto message = cpp_pubsub::msg::Signal();
        
        double time = count_ * 0.001;  
        
        message.sine_wave = std::sin(2 * M_PI * 10 * time);
        
        message.square_wave = std::sin(2 * M_PI * 1 * time) >= 0 ? 1.0 : -1.0;
        
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
