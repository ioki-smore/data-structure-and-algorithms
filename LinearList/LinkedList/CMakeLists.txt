PROJECT(LinkedList C)

add_library(SingleLinkedList STATIC SingleLinkedList/SingleLinkedList.c)
add_library(DoubleLinkedList STATIC DoubleLinkedList/DoubleLinkedList.c)

target_include_directories(SingleLinkedList PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(DoubleLinkedList PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})