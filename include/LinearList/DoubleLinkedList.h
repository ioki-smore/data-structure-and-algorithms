#ifndef DATASTRUCTURE_DOUBLELINKEDLIST_H
#define DATASTRUCTURE_DOUBLELINKEDLIST_H

#include "config.h"

/* DOUBLE LINKED LIST */
#define DOUBLE_LINKED_LIST(type) \
DEFINE_double_link_list(type)  \
IMPLEMENT_double_link_list(type)

/* DEFINE */
#define DEFINE_double_link_list(type) \
typedef struct abbr(D, type, Node,) { \
    type data;                        \
    struct abbr(D, type, Node,) *prior, *next; \
} abbr(D, type, Node,), *abbr(D, type, Linklist,);

/* IMPLEMENT */
#define IMPLEMENT_double_link_list(type) \
ds(bool) D##Insert##type(abbr(D, type, Node,) *p, abbr(D, type, Node,) *s) { \
    s->next = p->next;                   \
    p->next->prior = s;                  \
    s->prior = p;                        \
    p->next = s;                         \
    return true;                         \
}                                        \
ds(bool) D##Delete##type##Successor(abbr(D, type, Node,) *p) {               \
    abbr(D, type, Node,) *q = p->next;   \
    p->next = q->next;                   \
    q->next->prior = p;                  \
    free(q);                             \
    return true;                         \
}

#endif //DATASTRUCTURE_DOUBLELINKEDLIST_H
