#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0)
        return 0;

    struct Node *head = NULL, *tail = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int k;
    scanf("%d", &k);

    k = k % n;
    if (k == 0) {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    tail->next = head;

    int steps = n - k;
    struct Node* temp = head;
    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}