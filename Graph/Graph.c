#include "string.h"
#include "Graph.h"
#include "limits.h"

ds(void) BFS_MIN_Distance(ALGraph G, int u) {
    int d[G.vex_num];
    bool visited[G.vex_num];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < G.vex_num; ++i) {
        d[i] = INT_MAX;
    }
    visited[u] = true;
    d[u] = 0;
    Sq_Int_Queue Q;
    EnIntQueue(&Q, u);
    while (!isIntQueueEmpty(Q)) {
        DeIntQueue(&Q, &u);
        for (int w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w)) {
            if (!visited[w]) {
                visited[w] = true;
                d[w] = d[u] + 1;
                EnIntQueue(&Q, w);
            }
        }
    }
}
