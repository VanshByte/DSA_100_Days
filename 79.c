#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct { int node, weight; } Edge;
typedef struct { int node, dist; } PQNode;

Edge* adj[1005];
int adjSize[1005];
PQNode heap[100005];
int heapSize = 0;

void push(int node, int dist) {
    heap[heapSize].node = node;
    heap[heapSize].dist = dist;
    int i = heapSize++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].dist > heap[i].dist) {
            PQNode tmp = heap[p]; heap[p] = heap[i]; heap[i] = tmp;
            i = p;
        } else break;
    }
}

PQNode pop() {
    PQNode top = heap[0];
    heap[0] = heap[--heapSize];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, s = i;
        if (l < heapSize && heap[l].dist < heap[s].dist) s = l;
        if (r < heapSize && heap[r].dist < heap[s].dist) s = r;
        if (s == i) break;
        PQNode tmp = heap[s]; heap[s] = heap[i]; heap[i] = tmp;
        i = s;
    }
    return top;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adj[i] = (Edge*)malloc(m * 2 * sizeof(Edge));
        adjSize[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][adjSize[u]].node = v;
        adj[u][adjSize[u]++].weight = w;
        adj[v][adjSize[v]].node = u;
        adj[v][adjSize[v]++].weight = w;
    }

    int src;
    scanf("%d", &src);

    int dist[1005];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[src] = 0;
    push(src, 0);

    while (heapSize > 0) {
        PQNode cur = pop();
        int node = cur.node, d = cur.dist;
        if (d > dist[node]) continue;
        for (int i = 0; i < adjSize[node]; i++) {
            int nb = adj[node][i].node;
            int nd = dist[node] + adj[node][i].weight;
            if (nd < dist[nb]) {
                dist[nb] = nd;
                push(nb, nd);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF");
        else printf("%d", dist[i]);
        if (i < n) printf(" ");
    }
    printf("\n");

    return 0;
}