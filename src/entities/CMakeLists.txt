project(Entities)

set(curdir ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "Current directory is: ${CMAKE_CURRENT_SOURCE_DIR}")

FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
SET(entities_source_list "")
SET(entities_header_list "")
SET(tests_header_list "")
FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
        LIST(APPEND entities_source_list "${child}/${child}.cpp")
        LIST(APPEND entities_headers_list "${child}/${child}.h")
        LIST(APPEND tests_header_list "${child}/tests.h")
    ENDIF()
ENDFOREACH()
SET(result ${dirlist})

message(STATUS "Sources list: ${entities_source_list}")


add_library(entities entities.h ${entities_source_list} ${entities_headers_list})

target_link_libraries(entities domains)

#add_library(entities_tests basetest.h tests.h state.h ${tests_header_list})

#target_link_libraries(entities_tests entities)