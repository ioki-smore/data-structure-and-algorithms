cmake_minimum_required(VERSION 3.22.1)

PROJECT(DataStructure
        DESCRIPTION "for data structure learning"
        LANGUAGES C)

SET(CMAKE_C_STANDARD 11)

ADD_COMPILE_DEFINITIONS(AUTHOR="@smore")

ADD_COMPILE_OPTIONS(-Wno-unused-result)

ADD_DEFINITIONS(-fgnu89-inline)

ENABLE_TESTING()

INCLUDE(cmake/include.cmake)

HEADER_DIRECTORIES(header_dir_list)

LIST(LENGTH header_dir_list header_dir_list_count)

MESSAGE(STATUS "[INFO] Found ${header_dir_list_count} header directories.")

include_directories(${PROJECT_SOURCE_DIR} ${header_dir_list})

add_subdirectory(LinearList)
add_subdirectory(Stack)
add_subdirectory(Queue)
add_subdirectory(String)
add_subdirectory(Tree)
add_subdirectory(Graph)
add_subdirectory(Search)

add_subdirectory(test)

add_executable(data-structure main.c)

target_link_libraries(data-structure PRIVATE SequenceList LinkedList SingleLinkedList DoubleLinkedList)


add_test(SingleLinkedListTest test_single_linked_list)