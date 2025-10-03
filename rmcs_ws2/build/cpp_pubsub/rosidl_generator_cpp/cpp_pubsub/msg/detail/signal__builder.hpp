// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cpp_pubsub:msg/Signal.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cpp_pubsub/msg/signal.hpp"


#ifndef CPP_PUBSUB__MSG__DETAIL__SIGNAL__BUILDER_HPP_
#define CPP_PUBSUB__MSG__DETAIL__SIGNAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cpp_pubsub/msg/detail/signal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cpp_pubsub
{

namespace msg
{

namespace builder
{

class Init_Signal_square_wave
{
public:
  explicit Init_Signal_square_wave(::cpp_pubsub::msg::Signal & msg)
  : msg_(msg)
  {}
  ::cpp_pubsub::msg::Signal square_wave(::cpp_pubsub::msg::Signal::_square_wave_type arg)
  {
    msg_.square_wave = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_pubsub::msg::Signal msg_;
};

class Init_Signal_sine_wave
{
public:
  Init_Signal_sine_wave()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Signal_square_wave sine_wave(::cpp_pubsub::msg::Signal::_sine_wave_type arg)
  {
    msg_.sine_wave = std::move(arg);
    return Init_Signal_square_wave(msg_);
  }

private:
  ::cpp_pubsub::msg::Signal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_pubsub::msg::Signal>()
{
  return cpp_pubsub::msg::builder::Init_Signal_sine_wave();
}

}  // namespace cpp_pubsub

#endif  // CPP_PUBSUB__MSG__DETAIL__SIGNAL__BUILDER_HPP_
