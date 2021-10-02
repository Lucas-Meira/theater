project(Pages)

add_subdirectory(authenticated)

SET(pages_source_list "InitPage.cpp;RegisterUserPage.cpp;ListItemsPage.cpp;LogInPage.cpp;ItemsMenuPage.cpp")

add_library(pages ${pages_source_list})
target_link_libraries(pages authenticated_pages)
