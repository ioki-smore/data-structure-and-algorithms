PROJECT(Graph LANGUAGES C)

add_library(Graph STATIC Graph.c)

target_include_directories(Graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})