#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* adj[1005];
int adjSize[1005];
bool visited[1005];
bool recStack[1005];

bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbour = adj[node][i];
        if (!visited[neighbour]) {
            if (dfs(neighbour))
                return true;
        } else if (recStack[neighbour]) {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(m * 2 * sizeof(int));
        adjSize[i] = 0;
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }

    bool cycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                cycle = true;
                break;
            }
        }
    }

    printf("%s\n", cycle ? "YES" : "NO");

    return 0;
}