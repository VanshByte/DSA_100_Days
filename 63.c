#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* adj[1005];
int adjSize[1005];
bool visited[1005];

void dfs(int node) {
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbour = adj[node][i];
        if (!visited[neighbour])
            dfs(neighbour);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(m * 2 * sizeof(int));
        adjSize[i] = 0;
        visited[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int s;
    scanf("%d", &s);

    dfs(s);
    printf("\n");

    return 0;
}