// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cpp_pubsub:msg/Signal.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cpp_pubsub/msg/signal.h"


#ifndef CPP_PUBSUB__MSG__DETAIL__SIGNAL__STRUCT_H_
#define CPP_PUBSUB__MSG__DETAIL__SIGNAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Signal in the package cpp_pubsub.
typedef struct cpp_pubsub__msg__Signal
{
  double sine_wave;
  double square_wave;
} cpp_pubsub__msg__Signal;

// Struct for a sequence of cpp_pubsub__msg__Signal.
typedef struct cpp_pubsub__msg__Signal__Sequence
{
  cpp_pubsub__msg__Signal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_pubsub__msg__Signal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CPP_PUBSUB__MSG__DETAIL__SIGNAL__STRUCT_H_
