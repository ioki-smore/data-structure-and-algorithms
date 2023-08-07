#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#include "config.h"
#include "SingleLinkedList.h"

#define QUEUE(type, size) \
DEFINE_queue(type, size)  \
IMPLEMENT_queue_operation(type, size);

#define LINK_QUEUE(type) \
DEFINE_link_queue(type)  \
IMPLEMENT_link_queue_operation(type)

#define DEFINE_queue(type, size) \
typedef struct {                 \
    type data[size];             \
    int front, rear;             \
} Sq##_##type##_##Queue;

#define DEFINE_link_queue(type) \
DEFINE_single_linked_list(type) \
typedef struct {                \
    L##_##type##_##Node *front, *rear; \
} *type##_##LinkQueue;

#define IMPLEMENT_queue_operation(type, size) \
ds(void) Init##type##Queue(Sq##_##type##_##Queue *Q) { \
    Q->rear = Q->front = 0;                   \
}                                             \
ds(bool) is##type##QueueEmpty(Sq##_##type##_##Queue Q) { \
    return (Q.front == Q.rear);               \
}                                             \
ds(bool) En##type##Queue(Sq##_##type##_##Queue *Q, type elem) { \
    if ((Q->rear + 1) % size == Q->front) return false; \
    Q->data[Q->rear] = elem;                  \
    Q->rear = (Q->rear + 1) % size;           \
    return true;                              \
}                                             \
ds(bool) De##type##Queue(Sq##_##type##_##Queue *Q, type *elem) { \
    if (Q->rear == Q->front) return false;    \
    *elem = Q->data[Q->front];                \
    Q->front = (Q->front + 1) % size;         \
    return true;                              \
}

#define IMPLEMENT_link_queue_operation(type) \
ds(void) Init##type##LinkQueue(type##_##LinkQueue *Q) { \
    type##_##LinkQueue q = *Q;               \
    q->front = q->rear = (type##_##LinkNode *) malloc(sizeof(type##_##LinkNode)); \
    q->front->next = NULL;                   \
}                                            \
ds(bool) is##type##LinkQueueEmpty(type##_##LinkQueue Q) {                         \
    return (Q->front == Q->rear);            \
}                                            \
ds(bool) En##type##LinkQueue(type##_##LinkQueue *Q, type elem) {                  \
    type##_##LinkNode *s = (type##_##LinkNode *) malloc(sizeof(type##_##LinkNode)); \
    s->data = elem;                          \
    s->next = NULL;                          \
    type##_##LinkQueue q = *Q;               \
    q->rear->next = s;                       \
    q->rear = s;                             \
    return true;                             \
}                                            \
ds(bool) De##type##LinkQueue(type##_##LinkQueue *Q, type *elem) {                 \
    type##_##LinkQueue q = *Q;               \
    if (q->front == q->rear) return false;   \
    type##_##LinkNode *p = q->front->next;   \
    *elem = p->data;                         \
    q->front->next = p->next;                \
    if (q->rear == p)                        \
        q->rear = q->front;                  \
    free(p);                                 \
    return true;                             \
}

#endif //DATASTRUCTURE_QUEUE_H
