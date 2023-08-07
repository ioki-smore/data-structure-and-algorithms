#ifndef DATASTRUCTURE_SINGLELINKEDLIST_H
#define DATASTRUCTURE_SINGLELINKEDLIST_H

#include "config.h"

#define SINGLE_LINKED_LIST(type, fmt, end) \
DEFINE_single_linked_list(type)  \
IMPLEMENT_single_linked_list(type, fmt, end)

#define DEFINE_single_linked_list(type) \
typedef struct L##_##type##_##Node {    \
    type data;                          \
    struct L##_##type##_##Node *next;   \
} L##_##type##_##Node, *L##_##type##_##LinkList;

#define IMPLEMENT_single_linked_list(type, fmt, end) \
ds(bool) type##ListHeadInsert(L##_##type##_##LinkList *L) { \
    L##_##type##_##Node *s;                          \
    type x;                                          \
    (*L) = (L##_##type##_##LinkList) malloc(sizeof(L##_##type##_##Node)); \
    (*L)->next = NULL;                               \
    (void) scanf(fmt, &x);                           \
    while (x != end) {                               \
        s = (L##_##type##_##Node *) malloc(sizeof(L##_##type##_##Node));  \
        s->data = x;                                 \
        s->next = (*L)->next;                        \
        (*L)->next = s;                              \
        getchar();                                   \
        (void) scanf(fmt, &x);                       \
    }                                                \
    return true;                                     \
}                                                    \
ds(bool) type##ListTailInsert(L##_##type##_##LinkList *L) { \
    type x;                                          \
    (*L) = (L##_##type##_##LinkList) malloc(sizeof(L##_##type##_##Node)); \
    L##_##type##_##Node *s, *r = (*L);               \
    (void) scanf(fmt, &x);                           \
    while (x != end) {                               \
        s = (L##_##type##_##Node *) malloc(sizeof(L##_##type##_##Node)); \
        s->data = x;                                 \
        r->next = s;                                 \
        r = s;                                       \
        getchar();                                   \
        (void) scanf(fmt, &x);                       \
    }                                                \
    r->next = NULL;                                  \
    return true;                                     \
}                                                    \
ds(L##_##type##_##Node *) ListGet##type##Elem(L##_##type##_##LinkList L, int i) { \
    if (i < 1) return NULL;                          \
    int j = 1;                                       \
    L##_##type##_##Node *p = L->next;                \
    while (p != NULL && j < i) {                     \
        p = p->next;                                 \
        j++;                                         \
    }                                                \
    return p;                                        \
}                                                    \
ds(L##_##type##_##Node *) ListLocate##type##Elem(L##_##type##_##LinkList L, type e) { \
    L##_##type##_##Node *p = L->next;                \
    while (p != NULL && p->data != e)                \
        p = p->next;                                 \
    return p;                                        \
}                                                    \
ds(bool) ListInsert##type##Node(L##_##type##_##LinkList L, L##_##type##_##Node *s, int i) { \
    L##_##type##_##Node *p = ListGet##type##Elem(L, i - 1); \
    if (p == NULL) return false;                     \
    s->next = p->next;                               \
    p->next = s;                                     \
    return true;                                     \
}                                                    \
ds(bool) ListConvertForwardToBackwardInsert##type##Node(L##_##type##_##LinkList L, L##_##type##_##Node *s, int i) { \
    type tmp = s->data;                              \
    L##_##type##_##Node *p = ListGet##type##Elem(L, i - 1); \
    if (p == NULL) return false;                     \
    s->data = p->data;                               \
    s->next = p->next;                               \
    p->next = s;                                     \
    p->data = tmp;                                   \
    return true;                                     \
}                                                    \
ds(bool) ListDelete##type##NodeByIndex(L##_##type##_##LinkList L, int i) {          \
    L##_##type##_##Node *p = ListGet##type##Elem(L, i - 1); \
    if (p == NULL) return false;                     \
    L##_##type##_##Node *q = p->next;                \
    p->next = q->next;                               \
    free(q);                                         \
    return true;                                     \
}                                                    \
ds(bool) ListDelete##type##Node(L##_##type##_##Node *p) {   \
    L##_##type##_##Node *q = p->next;                \
    if (q == NULL) return false;                     \
    p->data = q->data;                               \
    p->next = q->next;                               \
    free(q);                                         \
    return true;                                     \
}                                                    \
ds(int) type##ListLen(L##_##type##_##LinkList L) {   \
    int i = 0;                                       \
    L##_##type##_##Node *p = L->next;                \
    while (p != NULL) {                              \
        p = p->next;                                 \
        i++;                                         \
    }                                                \
    return i;                                        \
}                                                    \
ds(void) print##type##List(L##_##type##_##LinkList L) {     \
    L##_##type##_##Node *p = L->next;                \
    while (p != NULL) {                              \
        (p->next == NULL) ? printf(fmt, p->data) : printf(fmt "->", p->data);     \
        p = p->next;                                 \
    }                                                \
    printf("\n");                                    \
}

#endif //DATASTRUCTURE_SINGLELINKEDLIST_H