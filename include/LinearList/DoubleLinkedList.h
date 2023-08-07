#ifndef DATASTRUCTURE_DOUBLELINKEDLIST_H
#define DATASTRUCTURE_DOUBLELINKEDLIST_H

#include "config.h"

#define DOUBLE_LINKED_LIST(type) \
DEFINE_double_link_list(type)  \
IMPLEMENT_double_link_list(type)

#define DEFINE_double_link_list(type) \
typedef struct DNode {          \
    type data;                  \
    struct DNode *prior, *next; \
} D##_##type##_##Node, *D##_##type##_##Linklist;

#define IMPLEMENT_double_link_list(type) \
ds(bool) D##Insert##type(D##_##type##_##Node *p, D##_##type##_##Node *s) { \
    s->next = p->next;                   \
    p->next->prior = s;                  \
    s->prior = p;                        \
    p->next = s;                         \
    return true;                         \
}                                        \
ds(bool) D##Delete##type##Successor(D##_##type##_##Node *p) {              \
    D##_##type##_##Node *q = p->next;    \
    p->next = q->next;                   \
    q->next->prior = p;                  \
    free(q);                             \
    return true;                         \
}

#endif //DATASTRUCTURE_DOUBLELINKEDLIST_H
