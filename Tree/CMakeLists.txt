project(Tree C)

add_library(Tree STATIC Tree.c)
add_library(UnionFindSet STATIC UnionFindSet.c)

target_include_directories(Tree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(UnionFindSet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Tree PRIVATE Stack)