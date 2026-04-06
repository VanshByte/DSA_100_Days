#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* adj[1005];
int adjSize[1005];
bool visited[1005];

bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbour = adj[node][i];
        if (!visited[neighbour]) {
            if (dfs(neighbour, node))
                return true;
        } else if (neighbour != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(E * 2 * sizeof(int));
        adjSize[i] = 0;
        visited[i] = false;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    bool cycle = false;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                cycle = true;
                break;
            }
        }
    }

    printf("%s\n", cycle ? "YES" : "NO");

    return 0;
}