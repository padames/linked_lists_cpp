cmake_minimum_required(VERSION 3.15)
project(ex2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex2
        ../common/OLList.cpp
        lab6Ex1.cpp)
