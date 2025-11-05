#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node*top=NULL;
void push();
void pop();
void peek();
void display();
int main(){
    int choice;
    while(1){
        printf("\n----- Stack Operations (Linked List Implementation) -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top Element)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
void push(){
    int value;
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    if (newnode==NULL){
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter the value to push:");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=top;
    top=newnode;
}
void pop(){
    struct Node*temp;
    if(top==NULL){
        printf("Stack Underflow\n");
        return;
    }
    temp=top;
    printf("Popped element: %d\n",temp->data);
    top=top->next;
    free(temp);
}   
void peek(){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n",top->data);
}
void display(){
    struct Node*temp;
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    temp=top;
    printf("Stack elements:\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}