#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Global head pointer for the list

// Function prototypes
void insert();
void deleteNode();
void search();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n----- Singly Linked List - List ADT -----\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                search();
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

// Function to insert a new element at a given position
void insert() {
    struct Node *newNode, *temp;
    int pos, value, count = 0;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;

    // Case 1: If the list is empty
    if (head == NULL) {
        head = newNode;
        printf("Inserted as the first element.\n");
        return;
    }

    // Count the current number of nodes
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Enter position (0 to %d): ", count);
    scanf("%d", &pos);

    if (pos < 0 || pos > count) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    // Case 2: Insert at the beginning
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
    }
    // Case 3: Insert at given position
    else {
        temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Element inserted successfully.\n");
}

// Function to delete an element at a given position
void deleteNode() {
    struct Node *temp = head, *prev;
    int pos, count = 0;

    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    // Count nodes
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Enter position (0 to %d) to delete: ", count - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= count) {
        printf("Invalid position!\n");
        return;
    }

    temp = head;

    // Case 1: Delete first node
    if (pos == 0) {
        head = head->next;
        free(temp);
    }
    // Case 2: Delete node in middle or end
    else {
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        prev = temp->next;
        temp->next = prev->next;
        free(prev);
    }

    printf("Element deleted successfully.\n");
}

// Function to search for an element in the list
void search() {
    struct Node* temp = head;
    int value, pos = 0, found = 0;

    if (head == NULL) {
        printf("List is empty! Nothing to search.\n");
        return;
    }

    printf("Enter the value to search: ");
    scanf("%d", &value);

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found at position %d.\n", value, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
        printf("Element %d not found in the list.\n", value);
}

// Function to display the linked list
void display() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Current List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}