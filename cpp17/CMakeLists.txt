cmake_minimum_required(VERSION 3.10)
project(cpp20)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_variant test_variant.cpp)
