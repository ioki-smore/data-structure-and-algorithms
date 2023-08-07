#ifndef DATASTRUCTURE_GRAPH_H
#define DATASTRUCTURE_GRAPH_H

#include "config.h"
#include "Stack.h"
#include "Queue.h"

#define MaxVertexNum 100

typedef char VertexType;
//typedef char InfoType;
typedef int EdgeType;

/* GRAPH */

#define ADJACENCY_MATRIX_GRAPH(v, e, size)  DEFINE_adjacency_matrix_graph(v, e, size)

#define ADJACENCY_LIST_GRAPH(size) \
DEFINE_adjacency_list_graph(size)  \
IMPLEMENT_adjacency_list_graph_operation(size)

/* DEFINE */
#define DEFINE_adjacency_matrix_graph(v, e, size) \
typedef struct {                                  \
    v abbr(M, v, Vex,)[size];                     \
    e abbr(M, e, Edge,)[size][size];              \
    int vex_num, arc_num;                         \
} abbr(M, v##_##e, Graph,);

#define DEFINE_adjacency_list_graph(size) \
typedef struct ArcNode {                  \
    int adj_vex;                          \
    struct ArcNode *next;                 \
    /* InfoType info; */                  \
} ArcNode;                                \
typedef struct VNode {                    \
    VertexType data;                      \
    ArcNode *first;                       \
} VNode, AdjList[size];                   \
typedef struct {                          \
    AdjList vertices;                     \
    int vex_num, arc_num;                 \
} ALGraph;

/* IMPLEMENT */
#define IMPLEMENT_adjacency_list_graph_operation(size) \
ds(bool) Adjacent(ALGraph G, int x, int y);      \
ds(ArcNode *)Neighbors(ALGraph G, int x);        \
ds(bool) InsertVertex(ALGraph G, int x);         \
ds(bool) DeleteVertex(ALGraph G, int x);         \
ds(bool) AddEdge(ALGraph G, int x, int y);       \
ds(bool) RemoveEdge(ALGraph G, int x, int y);    \
ds(int) FirstNeighbor(ALGraph G, int x) {        \
    return (x < 0 || x > G.vex_num) ? -1 : (G.vertices[x].first != NULL) ? G.vertices[x].first->adj_vex : -1; \
}                                                \
ds(int) NextNeighbor(ALGraph G, int x, int y) {  \
    if (x < 0 || x > G.vex_num) return -1;       \
    ArcNode *p = G.vertices[x].first;            \
    while (p && p->adj_vex != y) {               \
        p = p->next;                             \
    }                                            \
    return (p && p->next) ? p->next->adj_vex : -1;                                                            \
}                                                \
ds(int) Get_edge_value(ALGraph G, int x, int y); \
ds(bool) Set_edge_value(ALGraph G, int x, int y, int v);                                                      \
ds(void) visit(VNode elem) {                     \
    printf("%c", elem.data);                     \
    printf("\t%p", elem.first);                  \
}                                                \
TRAVERSE(size)

#define TRAVERSE(size) \
BFS_TRAVERSE(size)     \
DFS_TRAVERSE(size)

#define BFS_TRAVERSE(size) \
QUEUE(Int, size)           \
ds(void) BFS(ALGraph G, int v, Sq_Int_Queue Q, bool *visited) { \
    visit(G.vertices[v]);            \
    visited[v] = true;               \
    EnIntQueue(&Q, v);               \
    while (!isIntQueueEmpty(Q)) {    \
        DeIntQueue(&Q, &v);          \
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) { \
            if (!visited[w]) {       \
                visit(G.vertices[w]);\
                visited[w] = true;   \
                EnIntQueue(&Q, w);   \
            }    \
        }        \
    }            \
}                \
ds(void) BFSTraverse(ALGraph G) {                               \
    bool visited[size];    \
    for (int i = 0; i < G.vex_num; ++i) {                       \
        visited[i] = false;\
    }                      \
    Sq_Int_Queue Q;        \
    InitIntQueue(&Q);      \
    for (int i = 0; i < G.vex_num; ++i) {                       \
        if (!visited[i]) { \
            BFS(G, i, Q, visited);                              \
        }                  \
    }                      \
}

#define DFS_TRAVERSE(size) \
ds(void) DFS(ALGraph G, int v, bool *visited) { \
    visit(G.vertices[v]);                       \
    visited[v] = true;                          \
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) { \
        if (!visited[w]) {                      \
            DFS(G, w, visited);                 \
        }            \
    }                \
}                    \
ds(void) DFSTraverse(ALGraph G) {               \
    bool visited[size];    \
    for (int i = 0; i < G.vex_num; ++i) {       \
        visited[i] = false;\
    }                      \
    for (int i = 0; i < G.vex_num; ++i) {       \
        if (!visited[i]) { \
            DFS(G, i, visited);                 \
        }                  \
    }                      \
}

ADJACENCY_LIST_GRAPH(MaxVertexNum)

STACK(Int, MaxVertexNum)

ds(bool) TopologicalSort(ALGraph G, int *topology) {
    Sq_Int_Stack S;
    InitIntStack(&S);
    int indegree[G.vex_num], i;
    memset(indegree, 0, sizeof(indegree));
    for (i = 0; i < G.vex_num; ++i) {
        ArcNode *p = G.vertices[i].first;
        while (p) {
            indegree[p->adj_vex]++;
            p = p->next;
        }
    }
    for (i = 0; i < G.vex_num; ++i) {
        if (!indegree[i]) {
            PushInt(&S, i);
        }
    }
    int count = 0;
    while (!IntStackEmpty(S)) {
        PopInt(&S, &i);
        topology[count++] = i;
        for (ArcNode *p = G.vertices[i].first; p; p = p->next) {
            int v = p->adj_vex;
            if (!(--indegree[v])) {
                PushInt(&S, v);
            }
        }
    }
    return (count == G.vex_num);
}

#endif //DATASTRUCTURE_GRAPH_H
