project(Domains)

set(curdir ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "Current directory is: ${CMAKE_CURRENT_SOURCE_DIR}")

FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
SET(domain_source_list "capacity/capacity.cpp;date/date.cpp;email/email.cpp;idcode/idcode.cpp;name/name.cpp;password/password.cpp;phonenumber/phonenumber.cpp;playtype/playtype.cpp;rating/rating.cpp;registration/registration.cpp;role/role.cpp;time/time.cpp")
SET(domain_header_list "capacity/capacity.h;date/date.h;email/email.h;idcode/idcode.h;name/name.h;password/password.h;phonenumber/phonenumber.h;playtype/playtype.h;rating/rating.h;registration/registration.h;role/role.h;time/time.h")
SET(tests_header_list "capacity/tests.h;date/tests.h;email/tests.h;idcode/tests.h;name/tests.h;password/tests.h;phonenumber/tests.h;playtype/tests.h;rating/tests.h;registration/tests.h;role/tests.h;time/tests.h")

message(STATUS "${PROJECT_NAME} sources list: ${domain_source_list}")

add_library(domains domains.h basedomain.h ${domain_source_list} ${domain_headers_list})
add_library(domains_tests basetest.h tests.h ../state.h ${tests_header_list})

target_link_libraries(domains_tests domains)