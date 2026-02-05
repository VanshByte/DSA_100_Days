#include <stdio.h>

int main() {
    int p, q;
    scanf("%d", &p);

    int server1[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &server1[i]);
    }

    scanf("%d", &q);

    int server2[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &server2[i]);
    }

    int i = 0, j = 0;

    while (i < p && j < q) {
        if (server1[i] <= server2[j]) {
            printf("%d ", server1[i]);
            i++;
        } else {
            printf("%d ", server2[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", server1[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", server2[j]);
        j++;
    }

    return 0;
}
