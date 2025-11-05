#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to reverse a linked list and return new head
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;   // save next
        curr->next = prev;       // reverse pointer
        prev = curr;             // move prev forward
        curr = nextNode;         // move curr forward
    }
    return prev;   // prev is new head
}

// Helper to create a new node
struct ListNode* createNode(int x) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = x;
    node->next = NULL;
    return node;
}

// Helper to print list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d", temp->val);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

// Example usage
int main() {
    // Example: build list 1->2->3->4->5
    struct ListNode *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original list:\n");
    printList(head);

    head = reverseList(head);

    printf("Reversed list:\n");
    printList(head);

    // Free memory (skipped for brevity)
    return 0;
}
