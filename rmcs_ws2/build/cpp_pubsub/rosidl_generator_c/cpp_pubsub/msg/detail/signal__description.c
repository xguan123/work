// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from cpp_pubsub:msg/Signal.idl
// generated code does not contain a copyright notice

#include "cpp_pubsub/msg/detail/signal__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_cpp_pubsub
const rosidl_type_hash_t *
cpp_pubsub__msg__Signal__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf6, 0x59, 0x51, 0xcb, 0x1d, 0x67, 0x82, 0x88,
      0x66, 0x88, 0x68, 0x14, 0xc3, 0xae, 0xa4, 0x46,
      0x3b, 0x64, 0x7e, 0xb9, 0xb6, 0x26, 0x96, 0x38,
      0x28, 0x50, 0x74, 0x8c, 0x8f, 0xa0, 0x07, 0x57,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char cpp_pubsub__msg__Signal__TYPE_NAME[] = "cpp_pubsub/msg/Signal";

// Define type names, field names, and default values
static char cpp_pubsub__msg__Signal__FIELD_NAME__sine_wave[] = "sine_wave";
static char cpp_pubsub__msg__Signal__FIELD_NAME__square_wave[] = "square_wave";

static rosidl_runtime_c__type_description__Field cpp_pubsub__msg__Signal__FIELDS[] = {
  {
    {cpp_pubsub__msg__Signal__FIELD_NAME__sine_wave, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {cpp_pubsub__msg__Signal__FIELD_NAME__square_wave, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
cpp_pubsub__msg__Signal__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {cpp_pubsub__msg__Signal__TYPE_NAME, 21, 21},
      {cpp_pubsub__msg__Signal__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 sine_wave\n"
  "float64 square_wave";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
cpp_pubsub__msg__Signal__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {cpp_pubsub__msg__Signal__TYPE_NAME, 21, 21},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 38, 38},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
cpp_pubsub__msg__Signal__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *cpp_pubsub__msg__Signal__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
