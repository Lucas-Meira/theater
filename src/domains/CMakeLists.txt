project(Domains)

set(curdir ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "Current directory is: ${CMAKE_CURRENT_SOURCE_DIR}")

FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
SET(domain_source_list "")
SET(domain_header_list "")
SET(tests_source_list "")
SET(tests_header_list "")
FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
        LIST(APPEND domain_source_list "${child}/${child}.cpp")
        LIST(APPEND domain_headers_list "${child}/${child}.h")
        LIST(APPEND tests_source_list "${child}/tests.cpp")
        LIST(APPEND tests_header_list "${child}/tests.h")
    ENDIF()
ENDFOREACH()
SET(result ${dirlist})

message(STATUS "Sources list: ${domain_source_list}")


add_library(domains domains.h basedomain.h ${domain_source_list} ${domain_headers_list})
add_library(domains_tests basetest.h tests.h state.h ${tests_source_list} ${tests_header_list})

target_link_libraries(domains_tests domains)