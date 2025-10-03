cmake_minimum_required(VERSION 3.5)
project(cpp_pubsub)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)


set(msg_files
  "msg/Signal.msg"
)


rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  DEPENDENCIES std_msgs
)

add_executable(signal_generator src/signal_generator.cpp)
ament_target_dependencies(signal_generator rclcpp std_msgs)
rosidl_target_interfaces(signal_generator
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

add_executable(signal_processor src/signal_processor.cpp)
ament_target_dependencies(signal_processor rclcpp std_msgs)
rosidl_target_interfaces(signal_processor
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

install(TARGETS
  signal_generator
  signal_processor
  DESTINATION lib/${PROJECT_NAME})

ament_package()
