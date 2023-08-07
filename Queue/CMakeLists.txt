project(Queue C)

add_library(Queue STATIC Queue.c)

target_include_directories(Queue PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})