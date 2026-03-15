#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

Node* buildTree(int a[], int n) {
    if (n == 0 || a[0] == -1) return NULL;

    Node* root = createNode(a[0]);

    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;

    while (i < n && front < rear) {
        Node* curr = queue[front++];

        if (i < n && a[i] != -1) {
            curr->left = createNode(a[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && a[i] != -1) {
            curr->right = createNode(a[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    inorderTraversal(root);

    free(arr);
    return 0;
}