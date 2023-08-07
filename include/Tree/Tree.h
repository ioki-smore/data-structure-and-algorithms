#ifndef DATASTRUCTURE_TREE_H
#define DATASTRUCTURE_TREE_H

#include "config.h"

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

ds(void) visit(BiTree Node);

ds(void) PreOrder(BiTree T);

ds(void) InOrder(BiTree T);

ds(void) PostOrder(BiTree T);

typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

#define MAX_TREE_SIZE 100

#define SIZE 100

#define PARENT_TREE \
typedef struct {    \
    ElemType data;  \
    int parent;     \
} PTNode;           \
typedef struct {    \
    PTNode nodes[MAX_TREE_SIZE]; \
    int n;          \
} PTree;

#define CHILD_SIBLING_TREE \
typedef struct CSNode {    \
    ElemType data;         \
    struct CSNode * firstchild, *nextsibling; \
} CSNode, *CSTree;

#define UNION_FIND_SET(size) \
DEFINE_union_find_set(size)  \
IMPLEMENT_union_find_set_operation

#define DEFINE_union_find_set(size) \
int UFSets[size];

#define IMPLEMENT_union_find_set_operation \
ds(void) Initial(int S[]);                 \
ds(int) Find(const int S[], int x);        \
ds(void) Union(int S[], int Root1, int Root2);

PARENT_TREE
CHILD_SIBLING_TREE

UNION_FIND_SET(SIZE)

#endif //DATASTRUCTURE_TREE_H
