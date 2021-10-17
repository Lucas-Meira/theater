cmake_minimum_required(VERSION 3.15)
project(Theater)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("PDCurses")
link_directories("PDCurses")

set(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_CXX_FLAGS_DEBUG "-g")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Build flags: ${CMAKE_CXX_FLAGS}")
message(STATUS "Generator: ${CMAKE_GENERATOR}")
message(STATUS "Binaries: ${CMAKE_BINARY_DIR}")

add_subdirectory(src)

add_executable(main src/main.cpp)
add_executable(tests src/tests.cpp)

target_link_libraries(main entities presentation services)
target_link_libraries(main ${CURSES_LIBRARY})
target_link_libraries(tests domains_tests)
