#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node*insert(struct Node*head, int value){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return newnode;
    }
    struct Node*temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
    return head;
}

int findMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main(){
    int n, value;
    struct Node* head = NULL;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&value);
        head=insert(head,value);
    }
    int middle = findMiddle(head);
    printf("Middle element: %d\n", middle);
    return 0;
}