project(AuthenticatedPages)


SET(authenticated_pages_source_list "AuthenticatedInitPage.cpp;DeleteUserPage.cpp;UpdateUserPage.cpp;DeleteItemsPage.cpp;IncludeItemsPage.cpp;EditItemsPage.cpp;ViewItemsPage.cpp;PlayEnrollmentPage.cpp;PlayDisenrollmentPage.cpp")

add_library(authenticated_pages ${authenticated_pages_source_list})
