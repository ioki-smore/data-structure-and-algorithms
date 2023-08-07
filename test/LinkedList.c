#include "LinkedList.h"

ds(void)  recursion_delete(LinkList L, ElemType x) {
    LNode *p;
    if (L == NULL) return;
    p = L->next;
    (L->data == x) ? free(L) : NULL;
    recursion_delete(p, x);
}
ds(void)  delete_x_1(LinkList L, ElemType x) {
    LNode *p = L, *q = p->next, *c;
    while (q) {
        if (q->data == x) {
            p->next = q->next;
            c = q;
            q = q->next;
            free(c);
        } else {
            p = p->next;
            q = q->next;
        }
    }
}

ds(void)  delete_x_2(LinkList L, ElemType x) {
    LNode *p = L, *q = p->next, *c;
    while (q) {
        if (q->data != x) {
            p->next = q;
            p = q;
            q = q->next;
        } else {
            c = q;
            q = q->next;
            free(c);
        }
    }
    p->next = NULL;
}

ds(void)  reverse_print(LinkList L) {
    if (L->next != NULL) reverse_print(L->next);
    if (L->data) printf("%c", L->data);
}

ds(void)  delete_min(LinkList L) {
    LNode *p = L, *q = p->next, *c = q, *d;
    while (q) {
        if (q->data < c->data) {
            c = q;
            d = p;
        }
        p = p->next;
        q = q->next;
    }
    d->next = c->next;
    free(c);
}

ds(void)  reverse(LinkList L) {
    LNode *p = L->next, *q;
    L->next = NULL;
    while (p) {
        q = p->next;
        q->next = p;
        p->next = NULL;
        p = p->next;
    }
}