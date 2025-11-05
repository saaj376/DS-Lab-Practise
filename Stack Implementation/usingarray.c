#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push();
void pop();
void peek();
void display();

int main(){
    int choice;
    while(1){
        printf("\n----- Stack Operations (Array Implementation) -----\n");
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
    if(top==MAX-1){
        printf("Cannot add any more elements into the stack");
        return;
    }
    printf("Enter the value to push: ");
    scanf("%d",&value);
    top++;
    stack[top]=value;
}

void pop(){
    if(top==-1){
        printf("Stack empty!");
        return;
    }
    printf("Popped element: %d\n",stack[top]);
    top--;
}

void peek(){
    if(top==-1){
        printf("Stack Empty!");
        return;
    }
    printf("Top element is : %d\n",stack[top]);
}

void display(){
    if(top==-1){
        printf("Stack Empty!");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}