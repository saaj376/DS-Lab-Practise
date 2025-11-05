#include <stdio.h>
#include <stdlib.h>
#define MAX 100  // Maximum size of the stack

int stack[MAX];  // Array to hold stack elements
int top = -1;    // Stack is empty initially

// Function declarations
void push();
void pop();
void peek();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n----- Stack Operations (Array Implementation) -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top Element)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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

    return 0;
}

// Function to push an element into the stack
void push() {
    int value;

    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }

    printf("Enter the value to push: ");
    scanf("%d", &value);
    top++;
    stack[top] = value;
    printf("Element %d pushed successfully.\n", value);
}

// Function to pop the top element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }

    printf("Element %d popped successfully.\n", stack[top]);
    top--;
}

// Function to view the top element without removing it
void peek() {
    if (top == -1) {
        printf("Stack is empty! Nothing to peek.\n");
        return;
    }

    printf("Top element is: %d\n", stack[top]);
}

// Function to display all stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Current Stack (Top → Bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
