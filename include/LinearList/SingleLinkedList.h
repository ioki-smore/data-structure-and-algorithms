#ifndef DATASTRUCTURE_SINGLELINKEDLIST_H
#define DATASTRUCTURE_SINGLELINKEDLIST_H

#include "config.h"

#define SINGLE_LINKED_LIST(type, fmt, end) \
DEFINE_single_linked_list(type)  \
IMPLEMENT_single_linked_list(type, fmt, end)

#define DEFINE_single_linked_list(type) \
typedef struct abbr(L, type, Node,) {   \
    type data;                          \
    struct abbr(L, type, Node,) *next;  \
} abbr(L, type, Node,), *abbr(L, type, LinkList,);

#define IMPLEMENT_single_linked_list(type, fmt, end) \
ds(bool) type##ListHeadInsert(abbr(L, type, LinkList,) *L) { \
    abbr(L, type, Node,) *s;                         \
    type x;                                          \
    (*L) = (abbr(L, type, LinkList,)) malloc(sizeof(abbr(L, type, Node,))); \
    (*L)->next = NULL;                               \
    (void) scanf(fmt, &x);                           \
    while (x != end) {                               \
        s = (abbr(L, type, Node,) *) malloc(sizeof(abbr(L, type, Node,)));  \
        s->data = x;                                 \
        s->next = (*L)->next;                        \
        (*L)->next = s;                              \
        getchar();                                   \
        (void) scanf(fmt, &x);                       \
    }                                                \
    return true;                                     \
}                                                    \
ds(bool) type##ListTailInsert(abbr(L, type, LinkList,) *L) { \
    type x;                                          \
    (*L) = (abbr(L, type, LinkList,)) malloc(sizeof(abbr(L, type, Node,))); \
    abbr(L, type, Node,) *s, *r = (*L);              \
    (void) scanf(fmt, &x);                           \
    while (x != end) {                               \
        s = (abbr(L, type, Node,) *) malloc(sizeof(abbr(L, type, Node,)));  \
        s->data = x;                                 \
        r->next = s;                                 \
        r = s;                                       \
        getchar();                                   \
        (void) scanf(fmt, &x);                       \
    }                                                \
    r->next = NULL;                                  \
    return true;                                     \
}                                                    \
ds(abbr(L, type, Node,) *) ListGet##type##Elem(abbr(L, type, LinkList,) L, int i) { \
    if (i < 1) return NULL;                          \
    int j = 1;                                       \
    abbr(L, type, Node,) *p = L->next;               \
    while (p != NULL && j < i) {                     \
        p = p->next;                                 \
        j++;                                         \
    }                                                \
    return p;                                        \
}                                                    \
ds(abbr(L, type, Node,) *) ListLocate##type##Elem(abbr(L, type, LinkList,) L, type e) { \
    abbr(L, type, Node,) *p = L->next;                \
    while (p != NULL && p->data != e)                \
        p = p->next;                                 \
    return p;                                        \
}                                                    \
ds(bool) ListInsert##type##Node(abbr(L, type, LinkList,) L, abbr(L, type, Node,) *s, int i) { \
    abbr(L, type, Node,) *p = ListGet##type##Elem(L, i - 1); \
    if (p == NULL) return false;                     \
    s->next = p->next;                               \
    p->next = s;                                     \
    return true;                                     \
}                                                    \
ds(bool) ListConvertForwardToBackwardInsert##type##Node(abbr(L, type, LinkList,) L, abbr(L, type, Node,) *s, int i) { \
    type tmp = s->data;                              \
    abbr(L, type, Node,) *p = ListGet##type##Elem(L, i - 1); \
    if (p == NULL) return false;                     \
    s->data = p->data;                               \
    s->next = p->next;                               \
    p->next = s;                                     \
    p->data = tmp;                                   \
    return true;                                     \
}                                                    \
ds(bool) ListDelete##type##NodeByIndex(abbr(L, type, LinkList,) L, int i) { \
    abbr(L, type, Node,) *p = ListGet##type##Elem(L, i - 1); \
    if (p == NULL) return false;                     \
    abbr(L, type, Node,) *q = p->next;               \
    p->next = q->next;                               \
    free(q);                                         \
    return true;                                     \
}                                                    \
ds(bool) ListDelete##type##Node(abbr(L, type, Node,) *p) {   \
    abbr(L, type, Node,) *q = p->next;               \
    if (q == NULL) return false;                     \
    p->data = q->data;                               \
    p->next = q->next;                               \
    free(q);                                         \
    return true;                                     \
}                                                    \
ds(int) type##ListLen(abbr(L, type, LinkList,) L) {  \
    int i = 0;                                       \
    abbr(L, type, Node,) *p = L->next;               \
    while (p != NULL) {                              \
        p = p->next;                                 \
        i++;                                         \
    }                                                \
    return i;                                        \
}                                                    \
ds(void) print##type##List(abbr(L, type, LinkList,) L) {     \
    abbr(L, type, Node,) *p = L->next;               \
    while (p != NULL) {                              \
        (p->next == NULL) ? printf(fmt, p->data) : printf(fmt "->", p->data);     \
        p = p->next;                                 \
    }                                                \
    printf("\n");                                    \
}

#endif //DATASTRUCTURE_SINGLELINKEDLIST_H