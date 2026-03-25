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

#define MAX 1000

typedef struct {
    struct TreeNode* node;
    int hd;
} QueueItem;

int hdList[MAX];
int hdVals[MAX][MAX];
int hdCount[MAX];
int totalHD;

int findHD(int hd) {
    for (int i = 0; i < totalHD; i++)
        if (hdList[i] == hd) return i;
    hdList[totalHD] = hd;
    hdCount[totalHD] = 0;
    return totalHD++;
}

void verticalOrder(struct TreeNode* root) {
    if (root == NULL) return;

    QueueItem queue[MAX];
    int front = 0, rear = 0;

    totalHD = 0;

    queue[rear].node = root;
    queue[rear].hd   = 0;
    rear++;

    while (front < rear) {
        struct TreeNode* node = queue[front].node;
        int hd               = queue[front].hd;
        front++;

        int idx = findHD(hd);
        hdVals[idx][hdCount[idx]++] = node->val;

        if (node->left) {
            queue[rear].node = node->left;
            queue[rear].hd   = hd - 1;
            rear++;
        }
        if (node->right) {
            queue[rear].node = node->right;
            queue[rear].hd   = hd + 1;
            rear++;
        }
    }

    for (int i = 0; i < totalHD - 1; i++) {
        for (int j = 0; j < totalHD - i - 1; j++) {
            if (hdList[j] > hdList[j + 1]) {
                int tmp       = hdList[j];
                hdList[j]     = hdList[j + 1];
                hdList[j + 1] = tmp;

                int tmpc       = hdCount[j];
                hdCount[j]     = hdCount[j + 1];
                hdCount[j + 1] = tmpc;

                for (int k = 0; k < MAX; k++) {
                    int tmpv         = hdVals[j][k];
                    hdVals[j][k]     = hdVals[j + 1][k];
                    hdVals[j + 1][k] = tmpv;
                }
            }
        }
    }

    for (int i = 0; i < totalHD; i++) {
        for (int j = 0; j < hdCount[i]; j++) {
            if (j > 0) printf(" ");
            printf("%d", hdVals[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}