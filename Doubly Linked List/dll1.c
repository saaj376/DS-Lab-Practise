#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};
struct Node*head=NULL;

void insertatbeginning();
void insertatend();
void insertatposition();
void deleteatbeginning();
void deleteatend();
void deleteatposition();
void search();
void display();

int main(){
    int choice;
    while (1){
        printf("\n----- Doubly Linked List Menu -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Given Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Given Position\n");
        printf("7. Search Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                insertatbeginning();
                break;
            case 2:
                insertatend();
                break;
            case 3:
                insertatposition();
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                deleteAtPosition();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Exiting program...\n");
                exit(0);

        }
    }
    return 0;
}

void insertatbeginning(){
    int value;
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the value to be inserted: ");
    scanf("%d",&value);

    newnode->data=value;
    newnode->next=head;
    newnode->prev=NULL;

    if (head!=NULL){
        head->prev=newnode;
    head=newnode;
    }
}

void insertatend(){
    int value;
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    struct Node*temp=head;
    printf("Enter the value to be inserted: ");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;

    if (head==NULL){
        newnode->prev=NULL;
        head=newnode;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}
void insertatposition(){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    struct Node*temp=head;
    int value, pos, i;
    
}