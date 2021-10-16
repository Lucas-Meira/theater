project(Presentation)

add_subdirectory(pages)

SET(presentation_source_list "PageHandler.cpp")
SET(presentation_header_list "PageHandler.h;Pages.h")

add_library(presentation ${presentation_source_list} ${presentation_header_list})
target_link_libraries(presentation pages Curses)
