#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1)
        return;
    stack[++top] = val;
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("%d\n", stack[top--]);
}

void display() {
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int op, val;
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &val);
            push(val);
        }
        else if (op == 2) {
            pop();
        }
        else if (op == 3) {
            display();
        }
    }

    return 0;
}