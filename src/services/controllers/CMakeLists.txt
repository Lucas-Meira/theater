project(Controllers)

SET(controllers_source_list "ParticipantHandler.cpp;PlayHandler.cpp;RoomHandler.cpp;SessionHandler.cpp")
SET(controllers_header_list "controllers.h;ParticipantHandler.h;PlayHandler.h;RoomHandler.h;SessionHandler.h")

add_library(controllers ${controllers_source_list} ${controllers_header_list})

target_link_libraries(controllers entities interfaces)
