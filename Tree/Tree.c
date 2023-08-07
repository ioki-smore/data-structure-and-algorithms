#include "Tree.h"
#include "Stack.h"
#include "Queue.h"

ds(void) visit(BiTree Node) {
    printf("%c\t", Node->data);
}

ds(void) visitThreadNode(ThreadNode Node) {
    printf("%c\t", Node.data);
}

ds(void) PreOrder(BiTree T) {
    if (T != NULL) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

ds(void) InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

ds(void) PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

STACK(BiTree, MaxSize)

ds(void) InOrder2(BiTree T) {
    Sq_BiTree_Stack S;
    InitBiTreeStack(&S);
    BiTree p = T;
    while (p || !BiTreeStackEmpty(S)) {
        if (p) {
            PushBiTree(&S, p);
            p = p->lchild;
        } else {
            PopBiTree(&S, &p);
            visit(p);
            p = p->rchild;
        }
    }
}

ds(void) PreOrder2(BiTree T) {
    Sq_BiTree_Stack S;
    InitBiTreeStack(&S);
    BiTree p = T;
    while (p || !BiTreeStackEmpty(S)) {
        if (p) {
            visit(p);
            PushBiTree(&S, p);
            p = p->lchild;
        } else {
            PopBiTree(&S, &p);
            p = p->rchild;
        }
    }
}

QUEUE(BiTree, MaxSize)

ds(void) LevelOrder(BiTree T) {
    Sq_BiTree_Queue Q;
    InitBiTreeQueue(&Q);
    BiTree p;
    EnBiTreeQueue(&Q, T);
    while (!isBiTreeQueueEmpty(Q)) {
        DeBiTreeQueue(&Q, &p);
        visit(p);
        if (p->lchild != NULL) EnBiTreeQueue(&Q, p->lchild);
        if (p->rchild != NULL) EnBiTreeQueue(&Q, p->rchild);
    }
}

ds(void) InThread(ThreadTree *p, ThreadTree *pre) {
    if (p != NULL) {
        InThread((ThreadTree *) (*p)->lchild, pre);
        if ((*p)->lchild == NULL) {
            (*p)->lchild = *pre;
            (*p)->ltag = 1;
        }
        if ((*pre) != NULL && (*pre)->rchild == NULL) {
            (*pre)->rchild = *p;
            (*pre)->rtag = 1;
        }
        *pre = *p;
        InThread((ThreadTree *) (*p)->rchild, pre);
    }
}

ds(void) CreateInThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if (T != NULL) {
        InThread(&T, &pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}
// without head node
ds(ThreadNode *)FirstNode(ThreadNode *p) {
    while (p->ltag == 0) p = p->lchild;
    return p;
}

ds(ThreadNode *)NextNode(ThreadNode *p) {
    return (p->rtag == 0) ? FirstNode(p->rchild) : p->rchild;
}

ds(ThreadNode *)LastNode(ThreadNode *p) {
    while (p->rtag == 0) p = p->rchild;
    return p;
}

ds(ThreadNode *)PreNode(ThreadNode *p) {
    return (p->ltag == 0) ? LastNode(p->lchild) : p->lchild;
}

ds(void) Inorder(ThreadNode *T) {
    for (ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p)) {
        visitThreadNode(*p);
    }
}