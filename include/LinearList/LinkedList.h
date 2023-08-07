#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H

#include "config.h"
#include "SingleLinkedList.h"

SINGLE_LINKED_LIST(Char, "%c", '#')

#define LinkList L_Char_LinkList
#define LNode L_Char_Node
// 1
ds(void)  recursion_delete(LinkList L, ElemType x);
// 2
ds(void)  delete_x_1(LinkList L, ElemType x);

ds(void)  delete_x_2(LinkList L, ElemType x);
// 3
ds(void)  reverse_print(LinkList L);
// 4
ds(void)  delete_min(LinkList L);
// 5
ds(void)  reverse(LinkList L);

#endif //DATASTRUCTURE_LINKEDLIST_H
