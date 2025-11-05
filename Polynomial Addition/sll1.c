#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff;
    int pow;
    struct Node* next;
};

struct Node*createnode(int coeff,int pow){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->coeff=coeff;
    newnode->pow=pow;
    newnode->next=NULL;
    return newnode;
}

struct Node*insertterm(struct Node*head,int coeff,int pow){
    struct Node*newnode=createnode(coeff,pow);
    if (head==NULL){
        return newnode;
    }
    struct Node*temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
    return head;
}

void display(struct Node*poly){
    if (poly==NULL){
        printf("Empty Polynomial\n");
        return;
    }
    struct Node*temp=poly;
    while(temp!=NULL){
        printf("%dx^%d",temp->coeff,temp->pow);
        temp=temp->next;
        if(temp!=NULL)
            printf(" + ");
    }
}

struct Node*add(struct Node*poly1,struct Node*poly2){
    struct Node*result=NULL;
    struct Node*temp1=poly1;
    struct Node*temp2=poly2;
}