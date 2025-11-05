#include <stdio.h>
#define SIZE 5   // maximum size of queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (rear == SIZE - 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Enqueue function - to insert an element at the rear
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1) front = 0; // first insertion
    rear++;
    queue[rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

// Dequeue function - to remove an element from the front
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to dequeue.\n");
        return;
    }
    printf("%d dequeued from the queue.\n", queue[front]);
    front++;
    // Reset queue when all elements are dequeued
    if (front > rear) {
        front = rear = -1;
    }
}

// Peek function - to view the front element
void peek() {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to peek.\n");
        return;
    }
    printf("Front element is: %d\n", queue[front]);
}

// Display function - to show all elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function - menu-driven program
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
