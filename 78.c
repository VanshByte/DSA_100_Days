#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int node, weight;
} Edge;

Edge* adj[1005];
int adjSize[1005];

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

    int minDist[1005];
    int visited[1005];
    for (int i = 1; i <= n; i++) {
        minDist[i] = INT_MAX;
        visited[i] = 0;
    }
    minDist[1] = 0;

    int totalCost = 0;

    for (int iter = 0; iter < n; iter++) {
        int u = -1;
        for (int i = 1; i <= n; i++)
            if (!visited[i] && (u == -1 || minDist[i] < minDist[u]))
                u = i;

        visited[u] = 1;
        totalCost += minDist[u];

        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i].node;
            int w = adj[u][i].weight;
            if (!visited[v] && w < minDist[v])
                minDist[v] = w;
        }
    }

    printf("%d\n", totalCost);
    return 0;
}