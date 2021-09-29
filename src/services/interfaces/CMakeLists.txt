project(Interfaces)

SET(interfaces_header_list "ParticipantInterface.h")

add_library(interfaces ${interfaces_header_list})

set_target_properties(interfaces PROPERTIES LINKER_LANGUAGE CXX)