#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void create();
void insert();
void delete();
void display();
void search();

int b[MAX], n = 0;
int main(){
    int choice;
    while(1){
        printf("\n Main menu \n");
        printf("1. Create List \n");
        printf("2. Insert Element \n");
        printf("3. Delete Element \n");
        printf("4. Display List \n");
        printf("5. Search Element \n");
        printf("6. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                create();
                break;
            case 2:
                insert();
                break; 
            case 3:
                delete();
                break;
            case 4:
                display();
                break;  
            case 5:
                search();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}

void create(){
    int i;
    printf("Enter the number of elements to be added (max %d): ",MAX);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the element %d: ",i+1);
        scanf("%d",&b[i]);
    }
}


void insert() {
    int pos, val, i;
    printf("Enter the position to insert the element: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Invalid position! Please try again.\n");
        return;
    }
    printf("Enter the value to be inserted: ");
    scanf("%d", &val);

    for (i = n; i > pos; i--) {
        b[i] = b[i - 1];
    }

    b[pos] = val;
    n++;

    printf("Element inserted successfully.\n");
    display();
}
void delete(){
    int pos,i;
    printf("Enter the position of the element to be deleted: ");
    scanf("%d",&pos);
    if(pos<0 || pos>=n){
        printf("Invalid position! Please try again.\n");
        return;
    }
    for(i=pos;i<n-1;i++){
        b[i]=b[i+1];
    }
    n--;
    printf("Element deleted successfully.\n");
    display();
}

void display(){
    int i;
    if(n==0){
        printf("the list is empty.\n");
        return;
    }
    for(i=0;i<n;i++){
        printf("%d ",b[i]);
    }
    printf("\n");
}

void search(){
    int val,i,found=0;
    printf("Enter the value to be searched: ");
    scanf("%d",&val);
    for(i=0;i<n;i++){
        if(b[i]==val){
            printf("Element %d found at position %d.\n",val,i);
            found=1;
            break;
        }
    }
    if(!found){
        printf("Element %d not found in the list.\n",val);
    }
}