#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
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
        switch (choice) {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtPosition();
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
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void insertAtBeginning(){
    int value;
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert: ");
    scanf("%d",&value);
    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=head;
    if(head!=NULL)
        head->prev=newnode;
    head=newnode;
}
void insertAtEnd(){
    int value;
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    struct Node*temp=head;
    printf("Enter value to insert: ");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL){
        newnode->prev=NULL;
        head=newnode;
        return;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
    newnode->prev=temp;
}
void insertAtPosition(){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    struct Node*temp=head;
    int value,pos,i;
    printf("Enter the value to be inserted: ");
    scanf("%d",&value);
    printf("Enter the position to insert (starting from 1): ");
    scanf("%d",&pos);
    if (pos<=0){
        printf("Invalid position!\n");
        free(newnode);
        return;
    }
    newnode->data=value;
    if(pos==1){
        newnode->prev=NULL;
        newnode->next=head;
        if(head!=NULL)
            head->prev=newnode;
        head=newnode;
        return;
    }
    for(i=1;i<pos-1 && temp!=NULL;i++)
        temp=temp->next;
    if(temp==NULL){
        printf("Position out of range!\n");
        free(newnode);
        return;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    if(temp->next!=NULL){
        temp->next->prev=newnode;
    }
    temp->next = newnode;
    printf("Inserted %d at position %d.\n", value, pos);
}

void deleteAtBeginning(){
    struct Node*temp=head;
    if(head==NULL){
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    head=head->next;
    if(head!=NULL)
        head->prev=NULL;
    free(temp);
}

void deleteAtEnd(){
    struct Node*temp=head;
    if (head==NULL){
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    temp->prev->next=NULL;
    free(temp);
}

void deleteAtPosition(){
    struct Node*temp=head;
    int pos,i;
    if(head==NULL){
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    printf("Enter position to delete (starting from 1): ");
    scanf("%d",&pos);
    if(pos<=0){
        printf("Invalid position!\n");
        return;
    }
    if(pos==1){
        deleteAtBeginning();
        return;
    }
    for(i=1;i<pos && temp!=NULL;i++)
        temp=temp->next;
    if(temp==NULL){
        printf("Position out of range!\n");
        return;
    }
    if(temp->next!=NULL)
        temp->next->prev=temp->prev;
    if(temp->prev!=NULL)
        temp->prev->next=temp->next;
    free(temp);
}
void search(){
    struct Node*temp=head;
    int value,pos=1,found=0;
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    printf("Enter the value to be searched: ");
    scanf("%d",&value);
    while(temp!=NULL){
        if(temp->data==value){
            printf("Element %d found at position %d.\n",value,pos);
            found=1;
            break;  
        }
        temp=temp->next;
        pos++;
    }
    if (!found)
        printf("Element %d not found in the list.\n",value);
}