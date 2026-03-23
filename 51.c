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

Node* insert(Node* root, int val){
    if(root == NULL) return create(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

Node* LCA(Node* root, int a, int b){
    while(root){
        if(a < root->data && b < root->data)
            root = root->left;
        else if(a > root->data && b > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main(){
    int n;
    scanf("%d", &n);

    Node* root = NULL;

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    Node* ans = LCA(root, p, q);

    if(ans) printf("%d", ans->data);

    return 0;
}