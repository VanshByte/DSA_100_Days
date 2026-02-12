#include <stdio.h>

int main() {
    int m, n;
    int matrix[100][100];

    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix");
    return 0;
}
