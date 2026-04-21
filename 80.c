#include <stdio.h>

#define INF 1e18

int main() {
    int n;
    scanf("%d", &n);

    double dist[105][105];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            if (val == -1 && i != j)
                dist[i][j] = INF;
            else
                dist[i][j] = val;
        }
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] >= INF / 2)
                printf("-1");
            else
                printf("%d", (int)dist[i][j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}