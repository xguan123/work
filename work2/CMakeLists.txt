cmake_minimum_required(VERSION 3.20)

project(towork)

include_directories(include)

add_executable(
    ${PROJECT_NAME} 
    src/main.cpp 
    src/fun.cpp
)