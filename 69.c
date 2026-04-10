#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int node, weight;
} Edge;

typedef struct {
    int node, dist;
} PQNode;

Edge* adj[1005];
int adjSize[1005];

// Min-heap
PQNode heap[100005];
int heapSize = 0;

void push(int node, int dist) {
    heap[heapSize].node = node;
    heap[heapSize].dist = dist;
    int i = heapSize++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent].dist > heap[i].dist) {
            PQNode tmp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = tmp;
            i = parent;
        } else break;
    }
}

PQNode pop() {
    PQNode top = heap[0];
    heap[0] = heap[--heapSize];
    int i = 0;
    while (1) {
        int left = 2*i+1, right = 2*i+2, smallest = i;
        if (left  < heapSize && heap[left].dist  < heap[smallest].dist) smallest = left;
        if (right < heapSize && heap[right].dist < heap[smallest].dist) smallest = right;
        if (smallest == i) break;
        PQNode tmp = heap[smallest];
        heap[smallest] = heap[i];
        heap[i] = tmp;
        i = smallest;
    }
    return top;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
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
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    push(src, 0);

    while (heapSize > 0) {
        PQNode cur = pop();
        int node = cur.node, d = cur.dist;

        if (d > dist[node]) continue;

        for (int i = 0; i < adjSize[node]; i++) {
            int neighbour = adj[node][i].node;
            int newDist   = dist[node] + adj[node][i].weight;
            if (newDist < dist[neighbour]) {
                dist[neighbour] = newDist;
                push(neighbour, newDist);
            }
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("Node %d: INF\n", i);
        else
            printf("Node %d: %d\n", i, dist[i]);
    }

    return 0;
}