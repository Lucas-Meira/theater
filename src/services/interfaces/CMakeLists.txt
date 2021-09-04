project(Interfaces)

SET(interfaces_header_list "ParticipantInterface.h;PlayInterface.h;RoomInterface.h;SessionInterface.h;ServicesInterfaces.h")

add_library(interfaces ${interfaces_header_list})
