project(Stack C)

add_library(Stack STATIC Stack.c)

target_include_directories(Stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})