project(Domains)

set(curdir ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "Current directory is: ${CMAKE_CURRENT_SOURCE_DIR}")

FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
SET(domain_source_list "")
SET(domain_header_list "")
FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
        LIST(APPEND domain_source_list "${child}/${child}.cpp")
        LIST(APPEND domain_headers_list "${child}/${child}.h")
    ENDIF()
ENDFOREACH()
SET(result ${dirlist})

message(STATUS "Sources list: ${domain_source_list}")


add_library(domains domains.h basedomain.h ${domain_source_list} ${domain_headers_list})