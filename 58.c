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

struct Node* build(int* preorder, int* preIdx, int* inorder, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    struct Node* root = newNode(preorder[(*preIdx)++]);

    int inIdx = findIndex(inorder, inStart, inEnd, root->data);

    root->left = build(preorder, preIdx, inorder, inStart, inIdx - 1);
    root->right = build(preorder, preIdx, inorder, inIdx + 1, inEnd);

    return root;
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* preorder = (int*)malloc(sizeof(int) * n);
    int* inorder = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIdx = 0;
    struct Node* root = build(preorder, &preIdx, inorder, 0, n - 1);

    postorder(root);

    free(preorder);
    free(inorder);
    return 0;
}