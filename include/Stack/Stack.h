//
// Created by Administrator on 2023/7/29.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include "config.h"

#define STACK(type, size) \
DEFINE_stack(type, size)  \
IMPLEMENT_stack_operation(type, size)

#define LINK_STACK(type) \
DEFINE_link_stack        \
IMPLEMENT_link_stack_operation(type);

#define DEFINE_stack(type, size) \
typedef struct {                 \
    type data[size];             \
    int top;                     \
} Sq##_##type##_##Stack;

#define DEFINE_link_stack(type) \
typedef struct LinkNode {       \
    type data;                  \
    struct LinkNode *next;      \
} *LiStack;

#define IMPLEMENT_stack_operation(type, size) \
ds(void) Init##type##Stack(Sq##_##type##_##Stack *S) { \
         S->top = -1;                         \
}                                             \
ds(bool) type##StackEmpty(Sq##_##type##_##Stack S) {   \
    return (S.top == -1);                     \
}                                             \
ds(bool) Push##type(Sq##_##type##_##Stack *S, type elem) { \
    if (S->top == size - 1) return false;     \
    S->data[++S->top] = elem;                 \
    return true;                              \
}                                             \
ds(bool) Pop##type(Sq##_##type##_##Stack *S, type *elem) { \
    if (S->top == -1) return false;           \
    *elem = S->data[S->top--];                \
    return true;                              \
}                                             \
ds(bool) Get##type##StackTop(Sq##_##type##_##Stack S, type *elem) { \
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
