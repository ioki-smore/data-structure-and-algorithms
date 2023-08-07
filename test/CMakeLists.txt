PROJECT(test VERSION 1 LANGUAGES C)

add_library(LinkedList STATIC LinkedList.c)
add_library(SequenceList STATIC SequenceList.c)
add_library(SingleLinkedListTest STATIC SingleLinkedListTest.c)

target_include_directories(SingleLinkedListTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(SequenceList PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(LinkedList PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})