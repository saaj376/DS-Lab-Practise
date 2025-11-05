#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
}node;

node*createnode(int data){
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

node*insert(node*root,int data){
    if(root==NULL){
        return createnode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

void displaytree(node*root){
    if(root!=NULL){
        displaytree(root->left);
        displaytree(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    node*root=NULL;
    int n, value;
    printf("Enter number of elements to insert into BST: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        root=insert(root,value);
    }
    displaytree(root);
}