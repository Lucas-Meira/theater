project(Services)

add_subdirectory(controllers)
add_subdirectory(db)
add_subdirectory(interfaces)

add_library(services services.h)

target_link_libraries(services controllers db interfaces)
