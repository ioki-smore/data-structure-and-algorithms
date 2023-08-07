#ifndef DATASTRUCTURE_STRINGS_H
#define DATASTRUCTURE_STRINGS_H

#include "config.h"

#define MAXLEN 255

/* STRING */
#define STRING(size) \
DEFINE_string(size)  \
IMPLEMENT_string_operation

#define HEAP_STRING \
DEFINE_heap_string            \
IMPLEMENT_heap_string_operation

/* DEFINE */
#define DEFINE_string(size) \
typedef struct {            \
    char ch[size];        \
    int length;             \
} SString;

#define DEFINE_heap_string \
typedef struct {           \
    char *ch;              \
    int length;            \
} HString;

/* IMPLEMENT */
#define IMPLEMENT_string_operation \
ds(bool) StrAssign(SString *T, char chars); \
ds(bool) StrCopy(SString *T, SString S);    \
ds(bool) StrEmpty(SString S);      \
ds(int) StrCompare(SString S, SString T);   \
ds(int) StrLength(SString S);      \
ds(bool) SubString(SString *Sub, SString S, int pos, int len); \
ds(bool) Concat(SString *T, SString S1, SString S2);           \
ds(int) Index(SString S, SString T) {       \
    int i = 1, j = 1;              \
    while (i <= S.length && j <= T.length) {\
        if (S.ch[i] == T.ch[j]) {  \
            i++;                   \
            j++;                   \
        } else {                   \
            i = i - j + 2;         \
            j = 1;                 \
        }                          \
    }                              \
    return (j > T.length) ? (i - T.length) : 0;                \
}                                  \
ds(bool) ClearString(SString *S);  \
ds(bool) DestroyString(SString *S);

#define IMPLEMENT_heap_string_operation \
ds(bool) HStrAssign(HString *T, char chars); \
ds(bool) HStrCopy(HString *T, HString S);    \
ds(bool) HStrEmpty(HString S);          \
ds(int) HStrCompare(HString S, HString T);   \
ds(int) HStrLength(HString S);          \
ds(bool) SubHString(HString *Sub, HString S, int pos, int len); \
ds(bool) HStrConcat(HString *T, HString S1, HString S2);        \
ds(int) HStrIndex(HString S, HString T) {    \
    int i = 1, j = 1;                   \
    while (i <= S.length && j <= T.length) { \
        if (S.ch[i] == T.ch[j]) {       \
            i++;                        \
            j++;                        \
        } else {                        \
            i = i - j + 2;              \
            j = 1;                      \
        }                               \
    }                                   \
    return (j > T.length) ? (i - T.length) : 0;                 \
}                                       \
ds(bool) ClearHString(HString *S);      \
ds(bool) DestroyHString(HString *S);

#endif //DATASTRUCTURE_STRINGS_H
