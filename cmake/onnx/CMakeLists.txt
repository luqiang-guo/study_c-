cmake_minimum_required(VERSION 3.15)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
project(test LANGUAGES C CXX)

add_subdirectory(onnx)
add_subdirectory(test)