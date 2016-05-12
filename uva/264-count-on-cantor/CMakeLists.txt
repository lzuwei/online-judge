cmake_minimum_required(VERSION 3.5)
project(264_count_on_cantor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    cantor.cpp)

add_executable(264_count_on_cantor ${SOURCE_FILES})