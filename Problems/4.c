#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end
struct ListNode* insertEnd(struct ListNode* head, int val) {
    struct ListNode* newNode = createNode(val);
    if (head == NULL)
        return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to print linked list
void display(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d", temp->val);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse linked list (used in palindrome check)
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head;
    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check if linked list is palindrome
bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true; // Empty or single node list

    // Step 1: Find the middle using slow & fast pointers
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half
    struct ListNode* secondHalf = reverse(slow);
    struct ListNode* firstHalf = head;

    // Step 3: Compare both halves
    while (secondHalf) {
        if (firstHalf->val != secondHalf->val)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

// Driver function
int main() {
    struct ListNode* head = NULL;
    int n, val;

    printf("Enter number of nodes in the linked list: ");
    scanf("%d", &n);

    printf("Enter %d node values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    printf("\nOriginal List: ");
    display(head);

    if (isPalindrome(head))
        printf("✅ The linked list is a palindrome.\n");
    else
        printf("❌ The linked list is NOT a palindrome.\n");

    return 0;
}
