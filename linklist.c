#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *ptr;
}node;

node *createLinklist();
void traverse(node *start);
node *insertAtPlace(node *start, int place, int newValue);
void insertAfter(node *start, int value, int newValue);
node *insertBefore(node *start, int value, int newValue);
int  maxInList(node *start);
void linklistOperation(node *start);
void deleteAfter(node *start, int value);
node *deleteNode(node *start, int value);
node *deleteNodeAtPos(node *start, int position);

int main(){
	printf("enter -1 to stop entering data and display\n");
    node *start;
    start = createLinklist();
    traverse(start);
//    start = insertBefore(start, 5, 44);
//    traverse(start);
//    deleteAfter(start, 56);
//    traverse(start);
    start = deleteNodeAtPos(start, 1);
    traverse(start);
//    insertAfter(start, 5, 55);
//    traverse(start);
//    start = insertAtPlace(start, 3, 77);
//    traverse(start);
}

void traverse(node *start){
    node *temp = start;
    if(temp == NULL){
        printf("list is empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->ptr;
    }
    printf("\n");
}

node *createLinklist(){
    int i=1, elem;
    int mode  = 1;
    int count = 0;
    char conti = 'y';
    node *temp;
    node *start = (node*)malloc(sizeof(node));
    node *prevNode;
    if(start == NULL){
        printf("ERROR: memory can't be allocated\n");
        return start;
    }
    temp = start;
    prevNode = temp;
    printf("enter data of first node: ");
    scanf("%d", &elem);
    temp->data = elem;
    temp->ptr  = NULL;
    printf("select mode to enter data\n");
    printf("[1] enter fixed number of data\n");
    printf("[2] enter data till you want\n");
    printf("[3] create no new node\n");
    scanf("%d",&mode);
    switch(mode){
    case 1:
        printf("enter number of data to enter: ");
        scanf("%d", &count);
        i = 1;
        while(i <= count){
            node *newNode = (node *)malloc(sizeof(node));
            if(newNode == NULL){
                printf("ERROR: memory can't be allocated\n");
                return start;
            }
            printf("enter %d th data: ", i);
            scanf("%d", &elem);
            newNode->data = elem;
            prevNode->ptr = newNode;
            prevNode = newNode;
            newNode->ptr = NULL;
            i++;
        }
        break;
    case 2:
        printf("want to add more node? [y/n] ");
        scanf(" %c", &conti);
        while(conti == 'Y' || conti == 'y'){
            node *newNode = (node *)malloc(sizeof(node));
            if(newNode == NULL){
                printf("ERROR: memory can't be allocated\n");
                return start;
            }
            printf("enter data: ");
            scanf("%d", &elem);
            newNode->data = elem;
            prevNode->ptr = newNode;
            prevNode = newNode;
            newNode->ptr = NULL;
            printf("want to add more node? [y/n] ");
            scanf(" %c", &conti);
        }
        break;
        
    default:
        printf("no new node added\n");
        break;
    }
    prevNode->ptr = NULL;
    return start;
}

int maxInList(node* start){
    node *temp = start;
    int maxx = temp->data;
    while(temp->data != -1){
        if(temp->data > maxx){
            maxx = temp->data;
        }
        temp = temp->ptr;
    }
    return maxx;
}

void insertAfter(node *start, int value, int newValue){
    ///insert new value after
    node *temp;
    node *newNode;
    temp = start;
    if(temp == NULL){
        printf("insertion failed\nlist is empty\n");
        return;
    }
    while(temp->ptr != NULL && temp->data != value){
        temp = temp->ptr;
    }
    if(temp->ptr == NULL && temp->data != value){
        printf("! VALUE ERROR\n");
        printf("insertion operation failed\n");
        return;
    }
    newNode = (node *)malloc(sizeof(node));
    newNode->data = newValue;
    newNode->ptr  = temp->ptr;
    temp->ptr = newNode;
}

node *insertBefore(node *start, int value, int newValue){
    node *newStart = start;
    node *temp = start;
    if(start == NULL){
        printf("list is empty\n");
        return newStart;
    }
    else{
        node *prevNode;
        prevNode = temp;
        while(temp->ptr != NULL && temp->data != value){
            prevNode = temp;
            temp = temp->ptr;
        }
        if(temp->ptr == NULL && temp->data != value){
            printf("! VALUE ERROR\n");
            printf("insertion operation failed\n");
            return newStart;
        }
        node *newNode = (node *)malloc(sizeof(node));
        if(newNode == NULL){
            printf("ERROR: memory can't be allocated\n");
            return newStart;
        }
        newNode->data = newValue;
        newNode->ptr  = temp;
        if(temp == start){
            newStart = newNode;
        }
        else{
            prevNode->ptr = newNode;
        }
    }
    return newStart;
}

node *insertAtPlace(node *start, int place, int newValue){
    int  i=1;
    node *newStart = start;
    node *temp = start;
    node *prevNode;
    if(temp == NULL){
        printf("list is empty\n");
        return newStart;
    }
    prevNode = temp;
    while(temp->ptr != NULL && i < place){
        prevNode = temp;
        temp = temp->ptr;
        i++;
    }
    if(temp->ptr == NULL && i != place){
        printf("! INDEX ERROR\n");
        printf("insertion operation failed\n");
        return newStart;
    }
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = newValue;
    newNode->ptr  = temp;
    if(temp == start){
        newStart = newNode;
    }
    else{
        prevNode->ptr = newNode;
    }
    return newStart;
}

void deleteAfter(node *start, int value){
    node *temp;
    node *toDelete;
    temp = start;
    if(temp == NULL){
        printf("list is empty\n");
        return;
    }
    while(temp->ptr != NULL && temp->data != value){
        temp = temp->ptr;
    }
    if(temp->ptr == NULL && temp->data != value){
        printf("given data not in list\n");
        return;
    }
    if(temp->ptr == NULL && temp->data == value){
        printf("no value to delete after\n");
        return;
    }
    else{
        toDelete = temp->ptr;
        if((temp->ptr)->ptr != NULL){
            temp->ptr = (temp->ptr)->ptr;
        }
        else{
            temp->ptr = NULL;
        }
        free(toDelete);
    }
}

node *deleteNode(node *start, int value){
    node *newStart = NULL;
    node *temp = NULL;
    node *prevNode = NULL;
    newStart = start;
    temp = start;
    prevNode = temp;
    while(temp->ptr != NULL && temp->data != value){
        prevNode = temp;
        temp = temp->ptr;
    }
    if(temp->ptr == NULL && temp->data != value){
        printf("can't delete non existing value\n");
        return newStart;
    }
    if(temp == start && temp->ptr != NULL)
        newStart = temp->ptr;
    else if(temp->ptr == NULL)
        newStart = NULL;
    else{
        if(temp->ptr != NULL)
            prevNode->ptr = temp->ptr;
        else
            prevNode->ptr = NULL;
    }
    free(temp);
    return newStart;
}

node *deleteNodeAtPos(node *start, int position){
    int i=1;
    node *temp;
    node *newStart;
    node *toDelete;
    node *prevNode;
    temp = start;
    newStart = start;
    while(temp->ptr != NULL && i<position){
        prevNode = temp;
        temp = temp->ptr;
        i++;
    }
    if(temp->ptr == NULL && (i != position-1) && position != 1){
        printf("invalid position\n");
        return newStart;
    }
    if(position == 1 && temp->ptr != NULL){
        newStart = temp->ptr;
    }
    else if(position == 1 && temp->ptr == NULL){
        newStart = NULL;
    }
    else{
        if(temp->ptr != NULL)
            prevNode->ptr = temp->ptr;
        else{
            prevNode->ptr = NULL;
        }
    }
    free(toDelete);
    return newStart;
}
    
    
