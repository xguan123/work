cmake_minimum_required(VERSION 3.5)
project(cpp_pubsub)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(noise_generator src/noise_generator.cpp)
ament_target_dependencies(noise_generator rclcpp std_msgs)

add_executable(mid_filter_node src/mid_filter_node.cpp)
ament_target_dependencies(mid_filter_node rclcpp std_msgs)

add_executable(noise_generator2 src/noise_generator2.cpp)
ament_target_dependencies(noise_generator2 rclcpp std_msgs)

add_executable(lowpass_node src/lowpass_node.cpp)
ament_target_dependencies(lowpass_node rclcpp std_msgs)

install(TARGETS
  noise_generator
  mid_filter_node
  noise_generator2
  lowpass_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()