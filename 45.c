#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *left,*right;
}Node;

Node* newNode(int x){
    Node* n=(Node*)malloc(sizeof(Node));
    n->val=x;
    n->left=n->right=NULL;
    return n;
}

Node* buildTree(int a[],int n){
    if(n==0 || a[0]==-1) return NULL;

    Node* root=newNode(a[0]);
  Node* q[n];
    int f=0,r=0;
    q[r++]=root;

    int i=1;
    while(i<n && f<r){
        Node* cur=q[f++];

        if(i<n && a[i]!=-1){
            cur->left=newNode(a[i]);
            q[r++]=cur->left;
        }
        i++;

        if(i<n && a[i]!=-1){
      cur->right=newNode(a[i]);
            q[r++]=cur->right;
        }
        i++;
    }
  return root;
}

int height(Node* root){
    if(!root) return 0;
    int l=height(root->left);
    int r=height(root->right);
    return (l>r?l:r)+1;
}

int main(){
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    Node* root=buildTree(a,n);
    printf("%d",height(root));

    return 0;
}