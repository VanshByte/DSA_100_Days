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

struct TreeNode* lca(struct TreeNode* root, int p, int q) {
    if (root == NULL || root->val == p || root->val == q)
        return root;

    struct TreeNode* left  = lca(root->left,  p, q);
    struct TreeNode* right = lca(root->right, p, q);

    if (left && right)
        return root;

    return left ? left : right;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int p, q;
    scanf("%d %d", &p, &q);

    struct TreeNode* root = buildTree(arr, n);

    struct TreeNode* result = lca(root, p, q);

    printf("%d\n", result->val);

    return 0;
}
