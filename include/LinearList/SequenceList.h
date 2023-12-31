#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H

#include "config.h"

/* STATIC SEQUENCE LIST */
#define STATIC_SEQUENCE_LIST(type, size) \
DEFINE_static_sequence_list(type, size)  \
IMPLEMENT_static_sequence_list(type, size)

#define DYNAMIC_SEQUENCE_LIST(type, size) \
DEFINE_dynamic_sequence_list(type)        \
IMPLEMENT_dynamic_sequence_list(type)

/* DEFINE */
#define DEFINE_static_sequence_list(type, size) \
typedef struct abbr(Sq, type, List,) {          \
    type data[size];                            \
    int length;                                 \
} abbr(Sq, type, List,);

#define DEFINE_dynamic_sequence_list(type) \
typedef struct {                           \
    type *data;                            \
    int Max, length;                       \
} abbr(Seq, type, List,);

/* IMPLEMENT */
#define IMPLEMENT_static_sequence_list(type, size) \
ds(void) InitSq##type##List(abbr(Sq, type, List,) *List); \
ds(int) Sq##type##ListLength(abbr(Sq, type, List,) L);    \
ds(int) SqListLocate##type##Elem(abbr(Sq, type, List,) L, type e) { \
    for (int i = 0; i < L.length; i++) {     \
        if (L.data[i] == e) {                \
            return i + 1;                    \
        }                                    \
    }                                        \
    return 0;                                \
}                                            \
ds(type) SqListGet##type##Elem(abbr(Sq, type, List,) L, int i);     \
ds(bool) Sq##type##ListInsert(abbr(Sq, type, List,) *L, int i, type e) { \
    if (i < 1 || i > L->length + 1) return false;  \
    if (L->length > size) return false;            \
    for (int j = L->length; j >= i; j--) {         \
        L->data[j] = L->data[j - 1];               \
    }                                              \
    L->data[i - 1] = e;                            \
    L->length++;                                   \
    return true;                                   \
}                                                  \
ds(bool) Sq##type##ListDelete(abbr(Sq, type, List,) *L, int i, type *e) {\
    if (i < 1 || i > L->length) return false;      \
    *e = L->data[i - 1];                           \
    for (int j = i; j < L->length; j++) {          \
        L->data[j - 1] = L->data[j];               \
    }                                              \
    L->length--;                                   \
    return true;                                   \
}                                                  \
ds(void) PrintSq##type##List(abbr(Sq, type, List,) L);    \
ds(bool) EmptySq##type##List(abbr(Sq, type, List,) L);    \
ds(bool) DestroySq##type##List(abbr(Sq, type, List,) *L);

#define IMPLEMENT_dynamic_sequence_list(type)

// 10
ds(void) Converse(ElemType R[], int n, int p);

#endif //DATASTRUCTURE_LIST_H