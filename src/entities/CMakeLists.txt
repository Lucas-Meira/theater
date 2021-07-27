project(Entities)

add_library(entities entities.cpp entities.h)

target_link_libraries(entities domains)