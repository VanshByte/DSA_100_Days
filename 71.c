#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define DELETED -2

int table[1000];
int m;

int hash(int k) {
    return k % m;
}

void insert(int k) {
    for (int i = 0; i < m; i++) {
        int idx = (hash(k) + i * i) % m;
        if (table[idx] == EMPTY || table[idx] == DELETED) {
            table[idx] = k;
            return;
        }
    }
}

int search(int k) {
    for (int i = 0; i < m; i++) {
        int idx = (hash(k) + i * i) % m;
        if (table[idx] == EMPTY) return 0;
        if (table[idx] == k)    return 1;
    }
    return 0;
}

int main() {
    scanf("%d", &m);

    for (int i = 0; i < m; i++) table[i] = EMPTY;

    int q;
    scanf("%d", &q);

    char op[10];
    int key;

    while (q--) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            printf("%s\n", search(key) ? "FOUND" : "NOT FOUND");
        }
    }

    return 0;
}