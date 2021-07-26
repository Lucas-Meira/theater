project(TheaterExe)

add_subdirectory(domains)
add_subdirectory(entities)

add_executable(main main.cpp)

target_link_libraries(main entities)