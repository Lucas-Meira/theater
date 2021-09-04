project(DB)

SET(db_source_list "")
SET(db_header_list "db.h")

add_library(db ${db_source_list} ${db_header_list})
