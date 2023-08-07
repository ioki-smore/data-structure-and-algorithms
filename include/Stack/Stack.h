#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include "config.h"

/* STACK */
#define STACK(type, size) \
DEFINE_stack(type, size)  \
IMPLEMENT_stack_operation(type, size)

#define LINK_STACK(type) \
DEFINE_link_stack        \
IMPLEMENT_link_stack_operation(type);

/* DEFINE */
#define DEFINE_stack(type, size) \
typedef struct {                 \
    type data[size];             \
    int top;                     \
} abbr(Sq, type, Stack,);

#define DEFINE_link_stack(type) \
typedef struct LinkNode {       \
    type data;                  \
    struct LinkNode *next;      \
} *LiStack;

/* IMPLEMENT */
#define IMPLEMENT_stack_operation(type, size) \
ds(void) Init##type##Stack(abbr(Sq, type, Stack,) *S) { \
         S->top = -1;                         \
}                                             \
ds(bool) type##StackEmpty(abbr(Sq, type, Stack,) S) {   \
    return (S.top == -1);                     \
}                                             \
ds(bool) Push##type(abbr(Sq, type, Stack,) *S, type elem) { \
    if (S->top == size - 1) return false;     \
    S->data[++S->top] = elem;                 \
    return true;                              \
}                                             \
ds(bool) Pop##type(abbr(Sq, type, Stack,) *S, type *elem) { \
    if (S->top == -1) return false;           \
    *elem = S->data[S->top--];                \
    return true;                              \
}                                             \
ds(bool) Get##type##StackTop(abbr(Sq, type, Stack,) S, type *elem) { \
    if (S.top == -1) return false;            \
    *elem = S.data[S.top];                    \
    return true;                              \
}

// TODO implement error
#define IMPLEMENT_link_stack_operation(type) \
ds(void) InitStack(LiStack *S) {             \
         S->top = -1;                        \
}                                            \
ds(bool) StackEmpty(LiStack S) {             \
    return (S.top == -1);                    \
}                                            \
ds(bool) Push(LiStack *S, type elem) {       \
    if (S->top == MaxSize - 1) return false; \
    S->data[++S->top] = elem;                \
    return true;                             \
}                                            \
ds(bool) Pop(LiStack *S, type *elem) {       \
    if (S->top == -1) return false;          \
    *elem = S->data[S->top--];               \
    return true;                             \
}                                            \
ds(bool) GetTop(LiStack S, type *elem) {     \
    if (S.top == -1) return false;           \
    *elem = S.data[S.top];                   \
    return true;                             \
}

#endif //DATASTRUCTURE_STACK_H
