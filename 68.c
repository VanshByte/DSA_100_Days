#include <stdio.h>
#include <stdlib.h>

int* adj[1005];
int adjSize[1005];
int indegree[1005];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(m * sizeof(int));
        adjSize[i] = 0;
        indegree[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
        indegree[v]++;
    }

    int queue[1005];
    int front = 0, back = 0;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[back++] = i;

    while (front < back) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < adjSize[node]; i++) {
            int neighbour = adj[node][i];
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                queue[back++] = neighbour;
        }
    }

    printf("\n");

    return 0;
}