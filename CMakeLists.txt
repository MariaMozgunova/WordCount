cmake_minimum_required(VERSION 3.12) # version can be different

project(hw1) #name of your project

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(tests_hw1 tests.cpp) # add this executable

target_link_libraries(tests_hw1 PRIVATE gtest) # link google test to this executable