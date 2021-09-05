project(Presentation)

SET(presentation_source_list "PageHandler.cpp;pages/InitPage.cpp;pages/RegisterPage.cpp")
SET(presentation_header_list "PageHandler.h;Pages.h")

add_library(presentation ${presentation_source_list} ${presentation_header_list})
target_link_libraries(presentation Curses)
