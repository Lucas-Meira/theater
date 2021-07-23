cmake_minimum_required(VERSION 3.21)

set(CMAKE_GENERATOR "CodeBlocks - MinGW Makefiles")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Theater)

add_executable(main main.cpp domains.cpp)