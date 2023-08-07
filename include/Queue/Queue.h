#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#include "config.h"
#include "SingleLinkedList.h"

/* QUEUE */
#define QUEUE(type, size) \
DEFINE_queue(type, size)  \
IMPLEMENT_queue_operation(type, size);

#define LINK_QUEUE(type) \
DEFINE_link_queue(type)  \
IMPLEMENT_link_queue_operation(type)

/* DEFINE */
#define DEFINE_queue(type, size) \
typedef struct {                 \
    type data[size];             \
    int front, rear;             \
} abbr(Sq, type, Queue,);

#define DEFINE_link_queue(type) \
DEFINE_single_linked_list(type) \
typedef struct {                \
    abbr(L, type, Node,) *front, *rear; \
} *abbr(Link, type, Queue,);

/* IMPLEMENT */
#define IMPLEMENT_queue_operation(type, size) \
ds(void) Init##type##Queue(abbr(Sq, type, Queue,) *Q) { \
    Q->rear = Q->front = 0;                   \
}                                             \
ds(bool) is##type##QueueEmpty(abbr(Sq, type, Queue,) Q) { \
    return (Q.front == Q.rear);               \
}                                             \
ds(bool) En##type##Queue(abbr(Sq, type, Queue,) *Q, type elem) { \
    if ((Q->rear + 1) % size == Q->front) return false; \
    Q->data[Q->rear] = elem;                  \
    Q->rear = (Q->rear + 1) % size;           \
    return true;                              \
}                                             \
ds(bool) De##type##Queue(abbr(Sq, type, Queue,) *Q, type *elem) {\
    if (Q->rear == Q->front) return false;    \
    *elem = Q->data[Q->front];                \
    Q->front = (Q->front + 1) % size;         \
    return true;                              \
}

#define IMPLEMENT_link_queue_operation(type) \
ds(void) Init##type##LinkQueue(abbr(Link, type, Queue,) *Q) { \
    abbr(Link, type, Queue,) q = *Q;         \
    q->front = q->rear = (abbr(L, type, Node,) *) malloc(sizeof(abbr(L, type, Node,))); \
    q->front->next = NULL;                   \
}                                            \
ds(bool) is##type##LinkQueueEmpty(abbr(Link, type, Queue,) Q) {                         \
    return (Q->front == Q->rear);            \
}                                            \
ds(bool) En##type##LinkQueue(abbr(Link, type, Queue,) *Q, type elem) {                  \
    abbr(L, type, Node,) *s = (abbr(L, type, Node,) *) malloc(sizeof(abbr(L, type, Node,))); \
    s->data = elem;                          \
    s->next = NULL;                          \
    abbr(Link, type, Queue,) q = *Q;         \
    q->rear->next = s;                       \
    q->rear = s;                             \
    return true;                             \
}                                            \
ds(bool) De##type##LinkQueue(abbr(Link, type, Queue,) *Q, type *elem) {                 \
    abbr(Link, type, Queue,) q = *Q;         \
    if (q->front == q->rear) return false;   \
    abbr(L, type, Node,) *p = q->front->next;\
    *elem = p->data;                         \
    q->front->next = p->next;                \
    if (q->rear == p)                        \
        q->rear = q->front;                  \
    free(p);                                 \
    return true;                             \
}

#endif //DATASTRUCTURE_QUEUE_H
