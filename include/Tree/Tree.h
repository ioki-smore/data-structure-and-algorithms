#ifndef DATASTRUCTURE_TREE_H
#define DATASTRUCTURE_TREE_H

#include "config.h"
#include "Stack.h"
#include "Queue.h"

#define MAX_TREE_SIZE 100
#define SIZE 100

/* TREE */
#define BINARY_TREE(type, size, fmt) \
DEFINE_link_binary_tree(type)        \
IMPLEMENT_link_binary_tree(type, size, fmt)

#define THREAD_TREE(type, fmt) \
DEFINE_thread_tree(type)       \
IMPLEMENT_thread_tree(type, fmt)

#define PARENT_TREE(type, size) DEFINE_parent_tree(type, size)
#define CHILD_SIBLING_TREE(type)    DEFINE_child_sibling_tree(type)

/* UNION FIND SET */
#define UNION_FIND_SET(size) \
DEFINE_union_find_set(size)  \
IMPLEMENT_union_find_set_operation(size)

/* DEFINE */
#define DEFINE_link_binary_tree(type) \
typedef struct abbr(BiT, type, Node,) { \
    type data;                        \
    struct abbr(BiT, type, Node,) *lchild, *rchild; \
} abbr(BiT, type, Node,), *abbr(Bi, type, Tree,);

#define DEFINE_thread_tree(type) \
typedef struct abbr(Thread, type, Node,) { \
    type data;                   \
    struct abbr(Thread, type, Node,) *lchild, *rchild; \
    int ltag, rtag;              \
} abbr(Thread, type, Node,), *abbr(Thread, type, Tree,);

#define DEFINE_parent_tree(type, size) \
typedef struct {                       \
    type data;                         \
    int parent;                        \
} abbr(PT, type, Node,);               \
typedef struct {                       \
    abbr(PT, type, Node,) nodes[size]; \
    int n;                             \
} abbr(P, type, Tree,);

#define DEFINE_child_sibling_tree(type)\
typedef struct abbr(CS, type, Node,) { \
    type data;                         \
    struct abbr(CS, type, Node,) *firstchild, *nextsibling; \
} abbr(CS, type, Node,), *abbr(CS, type, Tree,);

#define DEFINE_union_find_set(size) int UFSets[size];

/* IMPLEMENT */
#define IMPLEMENT_link_binary_tree(type, size, fmt) \
ds(void) visitBiT##type##Node(abbr(Bi, type, Tree,) Node) { \
    printf(fmt "\t", Node->data);                   \
}                                                   \
TRAVERSE_link_binary_tree(type, size)

#define IMPLEMENT_thread_tree(type, fmt) \
ds(void) InThread##type##Tree(abbr(Thread, type, Tree,) *p, abbr(Thread, type, Tree,) *pre) { \
    if (p != NULL) {                     \
        InThread##type##Tree((abbr(Thread, type, Tree,) *) (*p)->lchild, pre);                \
        if ((*p)->lchild == NULL) {      \
            (*p)->lchild = *pre;         \
            (*p)->ltag = 1;              \
        }                                \
        if ((*pre) != NULL && (*pre)->rchild == NULL) {                                     \
            (*pre)->rchild = *p;         \
            (*pre)->rtag = 1;            \
        }                                \
        *pre = *p;                       \
        InThread##type##Tree((abbr(Thread, type, Tree,) *) (*p)->rchild, pre);                \
    }                                    \
}                                        \
ds(void) CreateInThread##type##Tree(abbr(Thread, type, Tree,) T) {                            \
    abbr(Thread, type, Tree,) pre = NULL;\
    if (T != NULL) {                     \
        InThread##type##Tree(&T, &pre);  \
        pre->rchild = NULL;              \
        pre->rtag = 1;                   \
    }                                    \
}                                        \
ds(void) visitThread##type##Node(abbr(Thread, type, Node,) Node) {                            \
    printf(fmt "\t", Node.data);         \
}                                        \
TRAVERSE_thread_tree(type)

#define IMPLEMENT_union_find_set_operation(size) \
ds(void) Initial(int S[]) {                      \
    for (int i = 0; i < size; i++) {             \
        S[i] = -1;                               \
    }                                            \
}                                                \
ds(int) Find(const int S[], int x) {             \
    while (S[x] >= 0) x = S[x];                  \
    return x;                                    \
}                                                \
ds(void) Union(int S[], int Root1, int Root2) {  \
    if (Root1 == Root2) return;                  \
    S[Root2] = Root1;                            \
}

#define TRAVERSE_link_binary_tree(type, size) \
RECURSIVE_TRAVERSE_link_binary_tree(type)     \
NON_RECURSIVE_TRAVERSE_link_binary_tree(type, size)

// without head node
#define TRAVERSE_thread_tree(type) \
ds(abbr(Thread, type, Node,) *) FirstThread##type##Node(abbr(Thread, type, Node,) *p) { \
    while (p->ltag == 0) p = p->lchild;                                                 \
    return p;                      \
}                                  \
ds(abbr(Thread, type, Node,) *) NextThread##type##Node(abbr(Thread, type, Node,) *p) {  \
    return (p->rtag == 0) ? FirstThread##type##Node(p->rchild) : p->rchild;             \
}                                  \
ds(abbr(Thread, type, Node,) *) LastThread##type##Node(abbr(Thread, type, Node,) *p) {  \
    while (p->rtag == 0) p = p->rchild;                                                 \
    return p;                      \
}                                  \
ds(abbr(Thread, type, Node,) *) PreThread##type##Node(abbr(Thread, type, Node,) *p) {   \
    return (p->ltag == 0) ? LastThread##type##Node(p->lchild) : p->lchild;              \
}                                  \
ds(void) Thread##type##TreeInorder(abbr(Thread, type, Node,) *T) {                      \
    for (abbr(Thread, type, Node,) *p = FirstThread##type##Node(T); p != NULL; p = NextThread##type##Node(p)) { \
        visitThread##type##Node(*p);                                                    \
    }                              \
}

#define RECURSIVE_TRAVERSE_link_binary_tree(type) \
ds(void) Bi##type##TreePreOrder(abbr(Bi, type, Tree,) T) { \
    if (T != NULL) {                              \
        visitBiT##type##Node(T);                  \
        Bi##type##TreePreOrder(T->lchild);        \
        Bi##type##TreePreOrder(T->rchild);        \
    }                                             \
}                                                 \
ds(void) Bi##type##TreeInOrder(abbr(Bi, type, Tree,) T) {  \
    if (T != NULL) {                              \
        Bi##type##TreeInOrder(T->lchild);         \
        visitBiT##type##Node(T);                  \
        Bi##type##TreeInOrder(T->rchild);         \
    }                                             \
}                                                 \
ds(void) Bi##type##TreePostOrder(abbr(Bi, type, Tree,) T) {\
    if (T != NULL) {                              \
        Bi##type##TreePostOrder(T->lchild);       \
        Bi##type##TreePostOrder(T->rchild);       \
        visitBiT##type##Node(T);                  \
    }                                             \
}

#define NON_RECURSIVE_TRAVERSE_link_binary_tree(type, size) \
STACK(abbr(Bi, type, Tree,), size)                          \
ds(void) Bi##type##TreeInOrderNonRecursive(abbr(Bi, type, Tree,) T) { \
    Sq_Bi_##type##_Tree_Stack S;                            \
    Init##Bi##_##type##_##TreeStack(&S);                    \
    abbr(Bi, type, Tree,) p = T;                            \
    while (p || !Bi##_##type##_##TreeStackEmpty(S)) {       \
        if (p) {                                            \
            PushBi##_##type##_##Tree(&S, p);                \
            p = p->lchild;                                  \
        } else {                                            \
            PopBi##_##type##_##Tree(&S, &p);                \
            visitBiT##type##Node(p);                        \
            p = p->rchild;                                  \
        }                                                   \
    }                                                       \
}                                                           \
ds(void) Bi##type##TreePreOrderNonRecursive(abbr(Bi, type, Tree,) T) {\
    Sq_Bi_##type##_Tree_Stack S;                            \
    InitBi##_##type##_##TreeStack(&S);                      \
    abbr(Bi, type, Tree,) p = T;                            \
    while (p || !Bi##_##type##_##TreeStackEmpty(S)) {       \
        if (p) {                                            \
            visitBiT##type##Node(p);                        \
            PushBi##_##type##_##Tree(&S, p);                \
            p = p->lchild;                                  \
        } else {                                            \
            PopBi##_##type##_##Tree(&S, &p);                \
            p = p->rchild;                                  \
        }                                                   \
    }                                                       \
}                                                           \
QUEUE(abbr(Bi, type, Tree,), size)                          \
ds(void) LevelOrder(abbr(Bi, type, Tree,) T) {              \
    Sq_Bi_##type##_Tree_Queue Q;                            \
    InitBi##_##type##_##TreeQueue(&Q);                      \
    abbr(Bi, type, Tree,) p;                                \
    EnBi##_##type##_##TreeQueue(&Q, T);                     \
    while (!isBi##_##type##_##TreeQueueEmpty(Q)) {          \
        DeBi##_##type##_##TreeQueue(&Q, &p);                \
        visitBiT##type##Node(p);                            \
        if (p->lchild != NULL) EnBi##_##type##_##TreeQueue(&Q, p->lchild); \
        if (p->rchild != NULL) EnBi##_##type##_##TreeQueue(&Q, p->rchild); \
    }                                                       \
}

#endif //DATASTRUCTURE_TREE_H
