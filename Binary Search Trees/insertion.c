#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};

struct Node*createnode(int data){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct Node*insert(struct Node*root,int data){
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

void displayTree(struct Node* root) {
    if (root != NULL) {
        displayTree(root->left);
        printf("Node: %d | ", root->data);
        if (root->left)
            printf("Left: %d | ", root->left->data);
        else
            printf("Left: NULL | ");
        if (root->right)
            printf("Right: %d\n", root->right->data);
        else
            printf("Right: NULL\n");
        displayTree(root->right);
    }
}
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 80);

    printf("--- Tree Structure ---\n");
    displayTree(root);

    return 0;
}