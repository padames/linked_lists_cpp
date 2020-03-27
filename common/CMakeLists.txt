cmake_minimum_required(VERSION 3.15)
project(common)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(common
    OLList.cpp
    OLList.h)
