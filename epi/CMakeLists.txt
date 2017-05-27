cmake_minimum_required(VERSION 3.5)
project(epi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    hello.cpp tree.h linkedlist.h utils/bits.h 7/7-1.h 7/7-2.h 7/7-5.h 7/7-6.h 10/10-1.h 11/11-6.h 8/8-1.h 10/10-2.h)

set(10_SOURCE_FILES
        binary_trees.cpp 10/10-1.h 10/10-2.h)

set(11_SOURCE_FILES
        heaps.cpp)

set(16_SOURCE_FILES
        recursion.cpp)

set(17_SOURCE_FILES
        dynamic_programming.cpp)

add_executable(hello ${SOURCE_FILES})
add_executable(binary_trees ${10_SOURCE_FILES})
add_executable(heaps ${11_SOURCE_FILES})
add_executable(recursion ${16_SOURCE_FILES})
add_executable(dp ${17_SOURCE_FILES})
