project(String C)

add_library(String STATIC Strings.c)

target_include_directories(Stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})