//
// Created by Administrator on 8/3/2023.
//
#include "Tree.h"

ds(void) Initial(int S[]) {
    for (int i = 0; i < SIZE; i++) {
        S[i] = -1;
    }
}

ds(int) Find(const int S[], int x) {
    while (S[x] >= 0) x = S[x];
    return x;
}

ds(void) Union(int S[], int Root1, int Root2) {
    if (Root1 == Root2) return;
    S[Root2] = Root1;
}