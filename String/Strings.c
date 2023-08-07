//
// Created by Administrator on 8/1/2023.
//

#include "Strings.h"

STRING(MAXLEN)

ds(void) get_next(SString T, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

ds(void) get_nextval(SString T, int nextval[]) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            i++;
            j++;
            nextval[i] = (T.ch[i] != T.ch[j]) ? j : nextval[j];
        } else {
            j = nextval[j];
        }
    }
}

ds(int) Index_KMP(SString S, SString T, const int next[]) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    return (j > T.length) ? (i - T.length) : 0;
}
