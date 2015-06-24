cmake_minimum_required(VERSION 3.2)
project(F4F)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)
add_executable(F4F ${SOURCE_FILES} main.c)