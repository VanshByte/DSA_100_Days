#include <stdio.h>
#include <stdlib.h>

int* adj[1005];
int adjSize[1005];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(m * 2 * sizeof(int));
        adjSize[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < adjSize[i]; j++) {
            printf("%d", adj[i][j]);
            if (j < adjSize[i] - 1) printf(" -> ");
        }
        printf("\n");
    }

    return 0;
}