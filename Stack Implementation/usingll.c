#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL; // Initially, the stack is empty

// Function declarations
void push();
void pop();
void peek();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n----- Stack Operations (Linked List Implementation) -----\n");
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

// Function to push an element onto the stack
void push() {
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed! Stack Overflow.\n");
        return;
    }

    printf("Enter the value to push: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = top; // Link new node to the previous top
    top = newNode;       // Make new node the new top

    printf("Element %d pushed successfully.\n", value);
}

// Function to pop (remove) the top element
void pop() {
    struct Node* temp;

    if (top == NULL) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }

    temp = top;
    printf("Element %d popped successfully.\n", top->data);
    top = top->next; // Move top to the next node
    free(temp);      // Free the popped node
}

// Function to view the top element (without removing it)
void peek() {
    if (top == NULL) {
        printf("Stack is empty! Nothing to peek.\n");
        return;
    }

    printf("Top element is: %d\n", top->data);
}

// Function to display the entire stack
void display() {
    struct Node* temp = top;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Current Stack (Top → Bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
