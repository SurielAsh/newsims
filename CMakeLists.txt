cmake_minimum_required(VERSION 3.13)
project(newptl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_executable(newptl main.cpp ptl_tools.h map_tools.h mltrd.h)