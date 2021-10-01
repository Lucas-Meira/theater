project(Presentation)

SET(presentation_source_list "PageHandler.cpp;pages/InitPage.cpp;pages/RegisterUserPage.cpp;pages/ListItemsPage.cpp;pages/LogInPage.cpp;pages/authenticated/AuthenticatedInitPage.cpp;pages/authenticated/DeleteUserPage.cpp;pages/authenticated/UpdateUserPage.cpp;pages/authenticated/DeleteItemsPage.cpp;pages/authenticated/IncludeItemsPage.cpp;pages/authenticated/ItemsMenuPage.cpp")
SET(presentation_header_list "PageHandler.h;Pages.h")

add_library(presentation ${presentation_source_list} ${presentation_header_list})
target_link_libraries(presentation Curses)
