// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cpp_pubsub:msg/Signal.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cpp_pubsub/msg/signal.hpp"


#ifndef CPP_PUBSUB__MSG__DETAIL__SIGNAL__STRUCT_HPP_
#define CPP_PUBSUB__MSG__DETAIL__SIGNAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cpp_pubsub__msg__Signal __attribute__((deprecated))
#else
# define DEPRECATED__cpp_pubsub__msg__Signal __declspec(deprecated)
#endif

namespace cpp_pubsub
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Signal_
{
  using Type = Signal_<ContainerAllocator>;

  explicit Signal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sine_wave = 0.0;
      this->square_wave = 0.0;
    }
  }

  explicit Signal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sine_wave = 0.0;
      this->square_wave = 0.0;
    }
  }

  // field types and members
  using _sine_wave_type =
    double;
  _sine_wave_type sine_wave;
  using _square_wave_type =
    double;
  _square_wave_type square_wave;

  // setters for named parameter idiom
  Type & set__sine_wave(
    const double & _arg)
  {
    this->sine_wave = _arg;
    return *this;
  }
  Type & set__square_wave(
    const double & _arg)
  {
    this->square_wave = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cpp_pubsub::msg::Signal_<ContainerAllocator> *;
  using ConstRawPtr =
    const cpp_pubsub::msg::Signal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cpp_pubsub::msg::Signal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cpp_pubsub::msg::Signal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cpp_pubsub::msg::Signal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cpp_pubsub::msg::Signal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cpp_pubsub::msg::Signal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cpp_pubsub::msg::Signal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cpp_pubsub::msg::Signal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cpp_pubsub::msg::Signal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cpp_pubsub__msg__Signal
    std::shared_ptr<cpp_pubsub::msg::Signal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cpp_pubsub__msg__Signal
    std::shared_ptr<cpp_pubsub::msg::Signal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Signal_ & other) const
  {
    if (this->sine_wave != other.sine_wave) {
      return false;
    }
    if (this->square_wave != other.square_wave) {
      return false;
    }
    return true;
  }
  bool operator!=(const Signal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Signal_

// alias to use template instance with default allocator
using Signal =
  cpp_pubsub::msg::Signal_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cpp_pubsub

#endif  // CPP_PUBSUB__MSG__DETAIL__SIGNAL__STRUCT_HPP_
