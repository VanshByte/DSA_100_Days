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
    if(root == NULL)
        return create(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

    int val;
    scanf("%d", &val);

    root = insert(root, val);

    inorder(root);

    return 0;
}