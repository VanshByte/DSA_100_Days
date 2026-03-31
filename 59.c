#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int* arr, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

struct Node* build(int* inorder, int inStart, int inEnd, int* postorder, int* postIdx) {
    if (inStart > inEnd) return NULL;

    struct Node* root = newNode(postorder[(*postIdx)--]);

    int inIdx = findIndex(inorder, inStart, inEnd, root->data);

    root->right = build(inorder, inIdx + 1, inEnd, postorder, postIdx);
    root->left = build(inorder, inStart, inIdx - 1, postorder, postIdx);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* inorder = (int*)malloc(sizeof(int) * n);
    int* postorder = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIdx = n - 1;
    struct Node* root = build(inorder, 0, n - 1, postorder, &postIdx);

    preorder(root);

    free(inorder);
    free(postorder);
    return 0;
}