project(Entities)

set(curdir ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "Current directory is: ${CMAKE_CURRENT_SOURCE_DIR}")

FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
SET(entities_source_list "participant/participant.cpp;play/play.cpp;room/room.cpp;session/session.cpp")
SET(entities_header_list "participant/participant.h;play/play.h;room/room.h;session/session.h")
SET(tests_header_list "participant/tests.h;play/tests.h;room/tests.h;session/tests.h")


message(STATUS "${PROJECT_NAME} sources list: ${entities_source_list}")

add_library(entities entities.h ${entities_source_list} ${entities_headers_list})

target_link_libraries(entities domains)

add_library(entities_tests tests.h basetest.h ../state.h ${tests_header_list})

target_link_libraries(entities_tests entities)