PROJECT(Search C)

add_library(Search STATIC Search.c)

target_include_directories(Search PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})