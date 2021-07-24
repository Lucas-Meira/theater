cmake_minimum_required(VERSION 3.15)

set(CMAKE_GENERATOR "CodeBlocks - MinGW Makefiles")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

message(STATUS "Build flags: ${CMAKE_CXX_FLAGS}")



project(Theater)

add_executable(main main.cpp domains.cpp entities.cpp)