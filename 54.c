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

void zigzag(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int level[size];

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            int idx      = leftToRight ? i : size - 1 - i;
            level[idx]   = node->val;

            if (node->left)  queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        for (int i = 0; i < size; i++)
            printf("%d ", level[i]);

        leftToRight = !leftToRight;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    zigzag(root);

    return 0;
}
