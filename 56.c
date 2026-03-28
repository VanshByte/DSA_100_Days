#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val   = val;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0) return NULL;

    struct TreeNode** nodes = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    for (int i = 0; i < n; i++)
        nodes[i] = (arr[i] == -1) ? NULL : newNode(arr[i]);

    for (int i = 0; i < n; i++) {
        if (nodes[i] == NULL) continue;
        int left  = 2 * i + 1;
        int right = 2 * i + 2;
        if (left  < n) nodes[i]->left  = nodes[left];
        if (right < n) nodes[i]->right = nodes[right];
    }

    struct TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

int isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) return 1;
    if (left == NULL || right == NULL) return 0;

    return (left->val == right->val)
        && isMirror(left->left,  right->right)
        && isMirror(left->right, right->left);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    printf("%s\n", isMirror(root->left, root->right) ? "YES" : "NO");

    return 0;
}