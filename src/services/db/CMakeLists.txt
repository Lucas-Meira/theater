project(DB)

SET(db_source_list "sqlite3.c;DBHandler.cpp")
SET(db_header_list "sqlite3.h;DBHandler.h")

add_library(db ${db_source_list} ${db_header_list})
