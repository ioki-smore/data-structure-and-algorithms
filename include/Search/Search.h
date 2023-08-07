#ifndef DATASTRUCTURE_SEARCH_H
#define DATASTRUCTURE_SEARCH_H

#include "config.h"

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

#endif //DATASTRUCTURE_SEARCH_H
