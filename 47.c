#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

Node* create(int x){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

Node* buildTree(int a[], int n){
    if(n == 0 || a[0] == -1) return NULL;

    Node* root = create(a[0]);

    Node* q[n];
    int front = 0, rear = 0;
    q[rear++] = root;

    int i = 1;

    while(i < n && front < rear){
        Node* cur = q[front++];

        if(i < n && a[i] != -1){
            cur->left = create(a[i]);
            q[rear++] = cur->left;
        }
        i++;

        if(i < n && a[i] != -1){
            cur->right = create(a[i]);
            q[rear++] = cur->right;
        }
        i++;
    }

    return root;
}

int height(Node* root){
    if(root == NULL) return 0;

    int l = height(root->left);
    int r = height(root->right);

    return (l > r ? l : r) + 1;
}

int main(){
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    Node* root = buildTree(a, n);

    printf("%d", height(root));

    return 0;
}