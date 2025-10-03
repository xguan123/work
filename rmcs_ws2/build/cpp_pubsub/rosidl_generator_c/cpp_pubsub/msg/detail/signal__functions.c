// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cpp_pubsub:msg/Signal.idl
// generated code does not contain a copyright notice
#include "cpp_pubsub/msg/detail/signal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
cpp_pubsub__msg__Signal__init(cpp_pubsub__msg__Signal * msg)
{
  if (!msg) {
    return false;
  }
  // sine_wave
  // square_wave
  return true;
}

void
cpp_pubsub__msg__Signal__fini(cpp_pubsub__msg__Signal * msg)
{
  if (!msg) {
    return;
  }
  // sine_wave
  // square_wave
}

bool
cpp_pubsub__msg__Signal__are_equal(const cpp_pubsub__msg__Signal * lhs, const cpp_pubsub__msg__Signal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sine_wave
  if (lhs->sine_wave != rhs->sine_wave) {
    return false;
  }
  // square_wave
  if (lhs->square_wave != rhs->square_wave) {
    return false;
  }
  return true;
}

bool
cpp_pubsub__msg__Signal__copy(
  const cpp_pubsub__msg__Signal * input,
  cpp_pubsub__msg__Signal * output)
{
  if (!input || !output) {
    return false;
  }
  // sine_wave
  output->sine_wave = input->sine_wave;
  // square_wave
  output->square_wave = input->square_wave;
  return true;
}

cpp_pubsub__msg__Signal *
cpp_pubsub__msg__Signal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_pubsub__msg__Signal * msg = (cpp_pubsub__msg__Signal *)allocator.allocate(sizeof(cpp_pubsub__msg__Signal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_pubsub__msg__Signal));
  bool success = cpp_pubsub__msg__Signal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_pubsub__msg__Signal__destroy(cpp_pubsub__msg__Signal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_pubsub__msg__Signal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_pubsub__msg__Signal__Sequence__init(cpp_pubsub__msg__Signal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_pubsub__msg__Signal * data = NULL;

  if (size) {
    data = (cpp_pubsub__msg__Signal *)allocator.zero_allocate(size, sizeof(cpp_pubsub__msg__Signal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_pubsub__msg__Signal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_pubsub__msg__Signal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cpp_pubsub__msg__Signal__Sequence__fini(cpp_pubsub__msg__Signal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cpp_pubsub__msg__Signal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cpp_pubsub__msg__Signal__Sequence *
cpp_pubsub__msg__Signal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_pubsub__msg__Signal__Sequence * array = (cpp_pubsub__msg__Signal__Sequence *)allocator.allocate(sizeof(cpp_pubsub__msg__Signal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_pubsub__msg__Signal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_pubsub__msg__Signal__Sequence__destroy(cpp_pubsub__msg__Signal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_pubsub__msg__Signal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_pubsub__msg__Signal__Sequence__are_equal(const cpp_pubsub__msg__Signal__Sequence * lhs, const cpp_pubsub__msg__Signal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_pubsub__msg__Signal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_pubsub__msg__Signal__Sequence__copy(
  const cpp_pubsub__msg__Signal__Sequence * input,
  cpp_pubsub__msg__Signal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cpp_pubsub__msg__Signal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_pubsub__msg__Signal * data =
      (cpp_pubsub__msg__Signal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_pubsub__msg__Signal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_pubsub__msg__Signal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_pubsub__msg__Signal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
