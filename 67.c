#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* adj[1005];
int adjSize[1005];
bool visited[1005];
int stack[1005];
int top = -1;

void dfs(int node) {
    visited[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbour = adj[node][i];
        if (!visited[neighbour])
            dfs(neighbour);
    }

    stack[++top] = node;
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
    }

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    while (top >= 0)
        printf("%d ", stack[top--]);
    printf("\n");

    return 0;
}