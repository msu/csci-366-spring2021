cmake_minimum_required(VERSION 3.16)
project(366_homework_2 C CXX)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../src)

add_executable(homework_2 homework_2.cpp)
target_link_libraries(homework_2 gtest gtest_main)
