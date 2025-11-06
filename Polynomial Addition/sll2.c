#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff;
    int pow;
    struct Node*next;
};

struct Node*create(int coeff, int pow){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->coeff=coeff;
    newnode->pow=pow;
    newnode->next=NULL;
    return newnode;
}

struct Node*insert(struct Node*head,int coeff, int pow){
    struct Node*newnode=create(coeff,pow);
    if (head==NULL){
        return newnode;
    }
    struct Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}

struct Node*add(struct Node*poly1, struct Node*poly2){
    struct Node*result=NULL;
    struct Node*temp1=poly1;
    struct Node*temp2=poly2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->pow>temp2->pow){
            result=insert(result,temp1->coeff,temp2->pow);
        }
        else if(temp1->pow<temp2->pow){
            result=insert(result,temp2->coeff,temp2->pow);
        }
        else{
            int sumcoeff=temp1->coeff+temp2->coeff;
            if(sumcoeff!=0){
                result=insert(result,sumcoeff,temp1->pow);
            }
            temp1=temp1->next;
            temp2=temp2->next;
    }
    while(temp1!=NULL){
        result=insert(result,temp1->coeff,temp1->pow);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        result=insert(result,temp2->coeff,temp2->pow);
        temp2=temp2->next;
    }
    return result;
}

int main(){
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n1, n2, coeff, pow;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);

    printf("Enter terms (coefficient and power) in descending order:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &coeff, &pow);
        poly1 = insertTerm(poly1, coeff, pow);
    }

    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n2);

    printf("Enter terms (coefficient and power) in descending order:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &coeff, &pow);
        poly2 = insertTerm(poly2, coeff, pow);
    }

    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    sum = add(poly1, poly2);

    printf("\nResultant Polynomial after Addition: ");
    display(sum);

    return 0;
}