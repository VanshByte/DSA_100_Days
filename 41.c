#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    if (rear == NULL) {
        front = rear = n;
    } else {
        rear->next = n;
        rear = n;
    }
}

int dequeue() {
    if (front == NULL) return -1;
    Node* t = front;
    int v = t->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(t);
    return v;
}

int main() {
    int n, x;
    char op[20];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &x);
            enqueue(x);
        } else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue());
        }
    }
    return 0;
}