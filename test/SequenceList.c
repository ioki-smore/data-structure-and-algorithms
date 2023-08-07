#include <string.h>
#include "SequenceList.h"

#define INT_MAX 0x7fffffff

STATIC_SEQUENCE_LIST(Char, MaxSize)

#define SqList Sq_Char_List

//----------------------------------------------------------------------------
// 1
ds(bool) DeleteMinElem(SqList *L, ElemType *e) {
    if (L->length == 0) {
        printf("%s", "ERROR: List is empty\n");
        return false;
    }
    *e = L->data[0];
    int pos;
    for (int i = 1; i < L->length; i++) {
        if (*e > L->data[i]) {
            *e = L->data[i];
            pos = i;
        }
    }
    L->data[pos] = L->data[L->length - 1];
    L->length--;
    return true;
}
// 2
ds(void) Reverse(SqList *L) {
    ElemType tmp;
    for (int i = 0; i < L->length / 2; ++i) {
        tmp = L->data[i];
        L->data[i] = L->data[L->length - 1 - i];
        L->data[L->length - 1 - i] = tmp;
    }
}
// 3
ds(bool) DeleteAllEqElem_1(SqList *L, ElemType e) {
    int j = 0;
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] != e) {
            L->data[j] = L->data[i];
            j++;
        }
    }
    L->length = j;
    return true;
}
// 3
ds(bool) DeleteAllEqElem_2(SqList *L, ElemType e) {
    int j = 0;
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] == e) {
            j++;
        } else {
            L->data[i - j] = L->data[i];
        }
    }
    L->length = L->length - j;
    return true;
}
// 4
ds(bool) DeleteOrderedBoundElem_1(SqList *L, ElemType s, ElemType t) {
    if (s >= t) {
        printf("%s", "ERROR: s or t is illegal\n");
        return false;
    }
    if (L->length == 0) {
        printf("%s", "ERROR: List is empty\n");
        return false;
    }
    int j = 0;
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] < s || L->data[i] > t) {
            L->data[j] = L->data[i];
            j++;
        }
    }
    L->length = j;
    return true;
}
// 4
ds(bool) DeleteOrderedBoundElem_2(SqList *L, ElemType s, ElemType t) {
    if (s >= t) {
        printf("%s", "ERROR: s or t is illegal\n");
        return false;
    }
    if (L->length == 0) {
        printf("%s", "ERROR: List is empty\n");
        return false;
    }

    int i = 0, j;
    for (; i < L->length && L->data[i] < s; ++i);
    if (i > L->length) {
        return false;
    }
    for (j = i; j < L->length && L->data[j] <= t; ++j);
    for (; j < L->length; j++, i++) {
        L->data[i] = L->data[j];
    }
    L->length = i;
    return true;
}
// 5
ds(bool) DeleteBoundElem_1(SqList *L, ElemType s, ElemType t) {
    if (s >= t) {
        printf("%s", "s or t is illegal\n");
        return false;
    }
    if (L->length == 0) {
        printf("%s", "ERROR: List is empty\n");
        return false;
    }
    int j = 0;
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] < s || L->data[i] > t) {
            L->data[j] = L->data[i];
            j++;
        }
    }
    L->length = j;
    return true;
}
// 5
ds(bool) DeleteBoundElem_2(SqList *L, ElemType s, ElemType t) {
    if (s >= t) {
        printf("%s", "s or t is illegal\n");
        return false;
    }
    if (L->length == 0) {
        printf("%s", "ERROR: List is empty\n");
        return false;
    }
    int j = 0;
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] >= s && L->data[i] <= t) {
            j++;
        } else {
            L->data[i - j] = L->data[i];
        }
    }
    L->length -= j;
    return true;
}
// 6
ds(bool) DeleteOrderedRepeat_1(SqList *L) {
    if (L->length == 0) return false;
    int j = 0;
    for (int i = 0; i < L->length; i++) {
        while (L->data[i] == L->data[j]) {
            i++;
        }
        j++;
        L->data[j] = L->data[i];
    }
    L->length = j + 1;
    return true;
}
// 6
ds(bool) DeleteOrderedRepeat_2(SqList *L) {
    if (L->length == 0) return false;
    int i, j = 1;
    for (i = 0; j < L->length; j++) {
        if (L->data[i] != L->data[j]) {
            L->data[++i] = L->data[j];
        }
    }
    L->length = i + 1;
    return true;
}
// 7
ds(bool) Merge_1(SqList A, SqList B, SqList *C) {
    if (A.length + B.length > MaxSize) return false;
    int i, j, k = 0;
    for (i = 0, j = 0; i < A.length && j < B.length; k++) {
        if (A.data[i] < B.data[j]) {
            C->data[k] = A.data[i++];
        } else {
            C->data[k] = B.data[j++];
        }
    }
    while (i < A.length) {
        C->data[k++] = A.data[i++];
    }
    while (i < B.length) {
        C->data[k++] = B.data[i++];
    }
    C->length = k;
    return true;
}
// 7
ds(bool) Merge_2(SqList A, SqList B, SqList *C) {
    if (A.length + B.length > MaxSize) return false;
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) {
        if (A.data[i] < B.data[j]) {
            C->data[k++] = A.data[i++];
        } else {
            C->data[k++] = B.data[j++];
        }
    }
    while (i < A.length) {
        C->data[k++] = A.data[i++];
    }
    while (i < B.length) {
        C->data[k++] = B.data[i++];
    }
    C->length = k;
    return true;
}

ds(void) ExchangeReverse(ElemType *A, int len) {
    ElemType tmp;
    for (int i = 0; i < len / 2; ++i) {
        tmp = A[i];
        A[i] = A[len - 1 - i];
        A[len - 1 - i] = tmp;
    }
}
// 8
ds(void) Exchange(ElemType A[], int m, int n) {
    ExchangeReverse(A, m);
    ExchangeReverse(A + m, n);
    ExchangeReverse(A, m + n);
}
// 9
ds(void) SearchExchangeOrInsert(SqList *L, ElemType e) {
    int l = 0, r = L->length - 1, mid;
    while (l <= r) {
        mid = (l + r) << 1;
        if (L->data[mid] == e) {
            break;
        } else if (L->data[mid] < e) l = mid + 1;
        else r = mid - 1;
    }
    if (L->data[mid] == e && mid != L->length - 1) {
        L->data[mid] = L->data[mid + 1];
        L->data[mid + 1] = e;
    }
    if (l > r) {
        for (int i = L->length - 1; i > r; i--) {
            L->data[i + 1] = L->data[i];
        }
        L->data[r] = e;
    }
}
// 10
ds(void) Converse(ElemType R[], int n, int p) {
    ExchangeReverse(R, p);
    ExchangeReverse(R + p, n - p);
    ExchangeReverse(R, n);
}
// 11
ds(int) TwoSequencesMedian(const int *A, const int *B, int n) {
    int la = 0, lb = 0, ra = n - 1, rb = n - 1, ma, mb;
    while (la != ra || lb != rb) {
        ma = (la + ra) << 1;
        mb = (lb + rb) << 1;
        if (A[ma] == B[mb]) {
            return A[ma];
        }
        if (A[ma] < B[mb]) {
            la = ((ra - la) & 1) == 0 ? ma : ma + 1;
            rb = mb;
        } else {
            lb = ((rb - lb) & 1) == 0 ? mb : mb + 1;
            ra = ma;
        }
    }
    return A[ma] > B[mb] ? B[mb] : A[ma];
}
// 12
ds(int) Majority(const int *A, int n) {
    int cnt = 1;
    int t = A[0];
    for (int i = 1; i < n; ++i) {
        if (A[i] == t) {
            cnt++;
        } else {
            if (cnt > 0) {
                cnt--;
            } else {
                t = A[i];
                cnt = 1;
            }
        }
    }
    if (cnt > 0) {
        for (int i = 0; i < n; ++i) {
            if (A[i] == t) {
                cnt++;
            }
        }
    }
    if (cnt > n / 2) return t;
    return -1;
}
// 13
ds(int) MissMin(const int *A, int n) {
    int i, *B;
    B = (int *) malloc(sizeof(int) * n);
    memset(B, 0, sizeof(int) * n);
    for (i = 0; i < n; ++i) {
        if (A[i] > 0 && A[i] < n) {
            B[A[i] - 1] = 1;
        }
    }
    for (i = 0; i < n; ++i) {
        if (B[i] == 0) {
            break;
        }
    }
    return i + 1;
}
// 14
ds(bool) is_min(int a, int b, int c) {
    return a <= b && a <= c;
}
// 14
ds(int) FineMinOfTriple(const int A[], int n, const int B[], int m, const int C[], int p) {
    int i = 0, j = 0, k = 0, MIN = INT_MAX, D;
    while (i < n && j < m && k < p && MIN > 0) {
        D = abs(A[i] - B[j]) + abs(A[i] - C[k]) + abs(B[j] - C[k]);
        if (D < MIN) MIN = D;
        if (is_min(A[i], B[j], C[k])) i++;
        else if (is_min(B[j], A[i], C[k])) j++;
        else k++;
    }
    return MIN;
}