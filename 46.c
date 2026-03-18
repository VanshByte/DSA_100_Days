#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void levelOrder(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode** queue = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));
    int front = 0, back = 0;
    queue[back++] = root;

    while (front < back) {
        int level_size = back - front;
        printf("[");

        for (int i = 0; i < level_size; i++) {
            struct TreeNode* node = queue[front++];
            printf("%d", node->val);
            if (i < level_size - 1) printf(", ");

            if (node->left)  queue[back++] = node->left;
            if (node->right) queue[back++] = node->right;
        }

        printf("]\n");
    }

    free(queue);
}

int main() {
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Level Order Traversal:\n");
    levelOrder(root);

    return 0;

}