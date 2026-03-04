#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

void pop() {
    if (top != -1)
        top--;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}