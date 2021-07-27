project(TheaterExe)

add_subdirectory(domains)
add_subdirectory(entities)

add_executable(main main.cpp)
add_executable(tests tests.cpp)

target_link_libraries(main entities)
target_link_libraries(tests domains_tests)
