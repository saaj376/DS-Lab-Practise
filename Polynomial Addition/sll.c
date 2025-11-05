#include <stdio.h>
#include <stdlib.h>

// Structure for a term (node) of the polynomial
struct Node {
    int coeff;      // coefficient
    int pow;        // power
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertTerm(struct Node** head, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to display a polynomial
void display(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp1 = poly1;
    struct Node* temp2 = poly2;

    // Traverse both polynomials
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->pow > temp2->pow) {
            insertTerm(&result, temp1->coeff, temp1->pow);
            temp1 = temp1->next;
        }
        else if (temp1->pow < temp2->pow) {
            insertTerm(&result, temp2->coeff, temp2->pow);
            temp2 = temp2->next;
        }
        else {
            // Same power — add coefficients
            int sumCoeff = temp1->coeff + temp2->coeff;
            if (sumCoeff != 0) // ignore zero coefficients
                insertTerm(&result, sumCoeff, temp1->pow);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    // Add remaining terms (if any)
    while (temp1 != NULL) {
        insertTerm(&result, temp1->coeff, temp1->pow);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insertTerm(&result, temp2->coeff, temp2->pow);
        temp2 = temp2->next;
    }

    return result;
}

// Main function
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n1, n2, coeff, pow;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter terms (coefficient and power) in descending order:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &coeff, &pow);
        insertTerm(&poly1, coeff, pow);
    }

    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter terms (coefficient and power) in descending order:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &coeff, &pow);
        insertTerm(&poly2, coeff, pow);
    }

    printf("\nFirst Polynomial: ");
    display(poly1);
    printf("Second Polynomial: ");
    display(poly2);

    sum = addPolynomials(poly1, poly2);

    printf("\nResultant Polynomial after Addition: ");
    display(sum);

    return 0;
}
