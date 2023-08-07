#ifndef DATASTRUCTURE_SEARCH_H
#define DATASTRUCTURE_SEARCH_H

#include "config.h"
#include "Tree.h"

typedef struct {
    ElemType *elem;
    int TableLen;
} SSTable;

ds(int) Search_Seq(SSTable ST, ElemType key) {
    ST.elem[0] = key;
    int i;
    for (i = ST.TableLen; ST.elem[i] != key; i--);
    return i;
}

ds(int) Binary_Search(SSTable L, ElemType key) {
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high) {
        mid = (low + high) << 1;
        if (L.elem[mid] == key) {
            return mid;
        } else if (L.elem[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

#define TREE_SEARCH(type, size, fmt) \
DEFINE_binary_sort_tree(type, size, fmt) \
IMPLEMENT_binary_sort_tree_operation(type)

/* DEFINE */
#define DEFINE_binary_sort_tree(type, size, fmt)    BINARY_TREE(type, size, fmt)

/* IMPLEMENT */
#define IMPLEMENT_binary_sort_tree_operation(type) \
ds(bool) type##BSTInsert(abbr(Bi, type, Tree,) *T, type k) { \
    if (T == NULL) {                               \
        (*T) = (abbr(Bi, type, Tree,)) malloc(sizeof (abbr(BiT, type, Node,))); \
        (*T)->data = k;                            \
        (*T)->lchild = (*T)->rchild = NULL;        \
        return true;                               \
    } else if (k == (*T)->data) {                  \
        return false;                              \
    } else if (k < (*T)->data) {                   \
        return  type##BSTInsert(&(*T)->lchild, k); \
    } else {                                       \
        return type##BSTInsert(&(*T)->rchild, k);  \
    }                                              \
}                                                  \
ds(void) Creat##type##BST(abbr(Bi, type, Tree,) *T, type str[], int n) {        \
    T = NULL;                                      \
    int i = 0;                                     \
    while (i < n) {                                \
        type##BSTInsert(T, str[i]);                \
        i++;                                       \
    }                                              \
}                                                  \
ds(abbr(BiT, type, Node,) *) type##BSTSearch(abbr(Bi, type, Tree,) T, type key) { \
    while(T != NULL && key != T->data) {           \
        T = (key < T->data) ? T->lchild : T->rchild;         \
    }                                              \
    return T;                                      \
}

TREE_SEARCH(Char, MaxSize, "%c")

#endif //DATASTRUCTURE_SEARCH_H
