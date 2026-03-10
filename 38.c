#include <stdio.h>
#include <string.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == 0) return;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front--;
    }
    deque[front] = x;
}

void push_back(int x) {
    if (rear == MAX - 1) return;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

void pop_front() {
    if (isEmpty()) return;

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() {
    if (isEmpty()) return;

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

int getFront() {
    if (isEmpty()) return -1;
    return deque[front];
}

int getBack() {
    if (isEmpty()) return -1;
    return deque[rear];
}

void display() {
    if (isEmpty()) return;

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            int x;
            scanf("%d", &x);
            push_front(x);
        }
        else if (strcmp(op, "push_back") == 0) {
            int x;
            scanf("%d", &x);
            push_back(x);
        }
        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(op, "front") == 0) {
            printf("%d\n", getFront());
        }
        else if (strcmp(op, "back") == 0) {
            printf("%d\n", getBack());
        }
        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        }
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(op, "display") == 0) {
            display();
        }
    }

    return 0;
}