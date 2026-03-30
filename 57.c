#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int n, int* arr) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;
    int i = 1;
    while (i < n && head < tail) {
        struct Node* curr = queue[head++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    free(queue);
    return root;
}

void mirror(struct Node* root) {
    if (root == NULL) return;
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(n, arr);
    mirror(root);
    inorder(root);
    free(arr);
    return 0;
}