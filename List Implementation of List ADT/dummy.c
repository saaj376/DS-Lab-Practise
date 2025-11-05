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

    if (head=NULL){
        head=newNode;
        printf("Inserted as the first element.\n");
        return; 
    }

    temp = head;
    while (temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("Enter position (0 to %d): ", count);
    scanf("%d",&pos);
    if (pos<0 || pos>count){
        printf("Invalid position!\n");
        free(newNode);
        return;
    }
    if (pos==0){
        newnode->next=head;
        head=newnode;
    }
    else{
        temp=head;
        for (int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        temp=temp->next;
        newnode->next=temp->next;
        temp->next=newnode;
    }