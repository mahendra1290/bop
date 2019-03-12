#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *back;
    struct node *next;
}node;

node *createDoubLinklist();
void traverse(node *start);
void traverseReverse(node *start);
node *insertAtPosi(node *start, int position, int newValue);
void insertAfter(node *start, int value, int newValue);
node *insertBefore(node *start, int value, int newValue);
void deleteAfter(node *start, int value);
node *deleteNode(node *start, int value);
node *deleteNodeAtPos(node *start, int position);
void doubleLinklistOper(node *start);
node *getReversed(node *start);

int main(){
    node *start;
    doubleLinklistOper(start);
    return 0;
}
//-------------------------------------------------------
node *createDoubLinklist(){
    int i=1, elem;
    int mode  = 1;
    int count = 0;
    char conti = 'y';
    node *temp;
    node *prevNode;
    node *start;
    node *newNode;
    start = (node*)malloc(sizeof(node));
    if(start == NULL){
        printf("ERROR: memory can't be allocated\n");
        return start;
    }
    temp = start;
    prevNode  = temp;
    printf("enter data of first node: ");
    scanf("%d", &elem);
    temp->data  = elem;
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
            newNode = (node *)malloc(sizeof(node));
            if(newNode == NULL){
                printf("ERROR: memory can't be allocated\n");
                return start;
            }
            printf("enter %d th data: ", i);
            scanf("%d", &elem);
            newNode->data = elem;
            prevNode->next = newNode;
            newNode->back = prevNode;
            prevNode = newNode;
            i++;
        }
        break;
    case 2:
        printf("want to add more node? [y/n] ");
        scanf(" %c", &conti);
        while(conti == 'Y' || conti == 'y'){
            newNode = (node *)malloc(sizeof(node));
            if(newNode == NULL){
                printf("ERROR: memory can't be allocated\n");
                return start;
            }
            printf("enter data: ");
            scanf("%d", &elem);
            newNode->data = elem;
            prevNode->next = newNode;
            newNode->back = prevNode;
            prevNode = newNode;
            printf("want to add more node? [y/n] ");
            scanf(" %c", &conti);
        }
        break;
    default:
        printf("no new node added\n");                             
        break;
    }
    prevNode->next = start;
    start->back = prevNode;
    return start;
}
//-------------------------------------------------------
void traverse(node *start){
    node *temp = start;
    if(temp == NULL){
        printf("list is empty\n");
        return;
    }
    else{
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while(temp != start);
        printf("\n");
    }   
}
//-------------------------------------------------------
void traverseReverse(node *start){
    node *temp = start;
    node *back = start->back;
    if(temp == NULL){
        printf("list is empty\n");
        return;
    }
    temp = back;
    do{
        printf("%d ", temp->data);
        temp = temp->back;
    }
    while(temp != back);
    printf("\n");
}
//-------------------------------------------------------
node *insertAtPosi(node *start, int position, int newValue){
    int i = 1;
    node *newStart = NULL;
    node *temp = NULL;
    node *newNode = NULL;
    node *prevNode = NULL;
    newStart = start;
    temp = start;
    if(temp == NULL){
        printf("list is empty\n");
        return newStart;
    }
    i = 1;
    while(temp->next != start && i < position){
        temp = temp->next;
        i++;
    }
    if(temp->next == start && position > i){
        printf("POSITION ERROR\n");
        printf("insertion operation failed\n");
        return newStart;
    }
    newNode = (node *)malloc(sizeof(node));
    newNode->data = newValue;
    if(position == 1){
        newNode->back = temp->back;
        newNode->next = temp;
        (temp->back)->next = newNode;
        temp->back = newNode;
        newStart = newNode;
    }
    else{
        prevNode = temp->back;
        prevNode->next = newNode;
        newNode->back  = prevNode;
        newNode->next  = temp;
        temp->back     = newNode;
    }
    return newStart;
}
//-------------------------------------------------------
void insertAfter(node *start, int value, int newValue){
    node *temp = NULL;
    node *newNode = NULL;
    temp = start;
    if(temp == NULL){
        printf("list is empty\n");
        return;
    }
    while(temp->next != start && temp->data != value){
        temp = temp->next;
    }
    if(temp->next == start && temp->data != value){
        printf("VALUE ERROR\n");
        printf("insertion operation failed\n");
        return;
    }
    newNode = (node *)malloc(sizeof(node));
    newNode->data = newValue;
    newNode->next = temp->next;
    newNode->back = temp;
    if(temp->next != NULL)
        (temp->next)->back = newNode;
    temp->next = newNode;
}
//-------------------------------------------------------
node *insertBefore(node *start, int value, int newValue){
    node *temp = NULL;
    node *newStart = NULL;
    node *newNode = NULL;
    temp = start;
    newStart = start;
    if(temp == NULL){
        printf("list is empty\n");
        return newStart;
    }
    while(temp->next != NULL && temp->data != value){
        temp = temp->next;
    }
    if(temp->next == NULL && temp->data != value){
        printf("VALUE ERROR\n");
        printf("insertion operation failed\n");
        return newStart; 
    }
    newNode = (node *)malloc(sizeof(node));
    newNode->data = newValue;
    newNode->next = temp;
    newNode->back = (temp->back);
    if(temp == start)
        newStart = newNode;
    else
        (temp->back)->next = newNode;
    temp->back = newNode;
    return newStart;
}
//-------------------------------------------------------
node *deleteNodeAtPos(node *start, int position){
    int i = 1;
    node *newStart = NULL;
    node *temp = NULL;
    node *newNode = NULL;
    node *prevNode = NULL;
    node *toDelete = NULL;
    newStart = start;
    temp = start;
    if(temp == NULL){
        printf("list is empty\n");
        return newStart;
    }
    i = 1;
    while(temp->next != NULL && i < position){
        temp = temp->next;
        i++;
    }
    if(temp->next == NULL && position > i){
        printf("POSITION ERROR\n");
        printf("insertion operation failed\n");
        return newStart;
    }
    toDelete = temp;
    if(position == 1 && temp->next != NULL){
        newStart = temp->next;
        (temp->next)->back = NULL;
    }
    else if(position == 1 && temp->next == NULL){
        newStart = NULL;
    }
    else{
        prevNode = temp->back;
        if(temp->next != NULL){
            prevNode->next = temp->next;
            (temp->next)->back = prevNode;
        }
        else{
            prevNode->next = NULL;
        }
    }
    free(toDelete);
    return newStart;
}
//----------------------------------------------------
node *deleteNode(node *start, int value){
    node *newStart = NULL;
    node *temp = NULL;
    node *newNode = NULL;
    node *prevNode = NULL;
    node *toDelete = NULL;
    newStart = start;
    temp = start;
    if(temp == NULL){
        printf("list is empty\n");
        return newStart;
    }
    while(temp->next != NULL && temp->data != value){
        temp = temp->next;
    }
    if(temp->next == NULL && temp->data != value){
        printf("VALUE ERROR\n");
        printf("insertion operation failed\n");
        return newStart;
    }
    toDelete = temp;
    if(temp == start && temp->next != NULL){
        newStart = temp->next;
        (temp->next)->back = NULL;
    }
    else if(temp == start && temp->next == NULL){
        newStart = NULL;
    }
    else{
        prevNode = temp->back;
        if(temp->next != NULL){
            prevNode->next = temp->next;
            (temp->next)->back = prevNode;
        }
        else{
            prevNode->next = NULL;
        }
    }
    free(toDelete);
    return newStart;
}
//------------------------------------------------------------
void deleteAfter(node *start, int value){
    node *temp = NULL;
    node *newNode = NULL;
    temp = start;
    node *toDelete = NULL;
    if(temp == NULL){
        printf("list is empty\n");
        return;
    }
    while(temp->next != NULL && temp->data != value){
        temp = temp->next;
    }
    if(temp->next == NULL && temp->data != value){
        printf("VALUE ERROR\n");
        printf("insertion operation failed\n");
        return;
    }
    if(temp->next != NULL){
        toDelete = temp->next;
        if((temp->next)->next != NULL){
            temp->next = (temp->next)->next;
            (temp->next)->back = temp;
        }
        else
            temp->next = NULL;
        free(toDelete);   
    }
    else{
        printf("next node does't exist\n");
    }
}
//-------------------------------------------------------
void doubleLinklistOper(node *start){
    printf("double linklist operations to perform\n");
    char conti = 'y';
    int mainChoice;
    int subChoice;
    int position;
    int value, newValue;
    while(conti == 'y' || conti == 'Y'){
        printf("-------------------------------\n");
        printf("[1] create double linklist\n");
        printf("[2] insert value in linklist\n");
        printf("[3] delete value in linklist\n");
        printf("[4] traverse\n");
        printf("[5] traverse reverse\n");
        printf("-------------------------------\n");
        printf("enter operation to perform : ");
        scanf("%d", &mainChoice);
        switch(mainChoice){
        case 1:
            start = createDoubLinklist();
            break;
        case 2:
            printf("-----------------------------\n");
            printf("[1] to insert after a value\n");
            printf("[2] to insert before a value\n");
            printf("[3] to insert at position\n");
            printf("-----------------------------\n");
            printf("which way you want to insert : ");
            scanf("%d", &subChoice);
            switch(subChoice){
            case 1:
                printf("after which value to insert ? : ");
                scanf("%d", &value);
                printf("enter value to insert : ");
                scanf("%d", &newValue);
                insertAfter(start, value, newValue);
                break;
            case 2:
                printf("before which value to insert ? : ");
                scanf("%d", &value);
                printf("enter value to insert : ");
                scanf("%d", &newValue);
                start = insertBefore(start, value, newValue);
                break;
            case 3:
                printf("position to insert : ");
                scanf("%d", &position);
                printf("enter value to insert : ");
                scanf("%d", &newValue);
                start = insertAtPosi(start, position, newValue);
                break;
            default:
                printf("not a valid input\n");
                break;
            }
            break;
        case 3:
            printf("-----------------------------\n");
            printf("[1] to delete after a value\n");
            printf("[2] to delete a value\n");
            printf("[3] to delete a value at position\n");
            printf("-----------------------------\n");
            printf("which way you want to delete : ");
            scanf("%d", &subChoice);
            switch(subChoice){
            case 1:
                printf("after which value to delete ? : ");
                scanf("%d", &value);
                deleteAfter(start, value);
                break;
            case 2:
                printf("enter value to delete: ");
                scanf("%d", &value);
                start = deleteNode(start, value);
                break;
            case 3:
                printf("position to delete : ");
                scanf("%d", &position);
                start = deleteNodeAtPos(start, position);
                break;
            default:
                printf("not a valid input\n");
                break;
            }
            break;
        case 4:
            traverse(start);
            break;
        case 5:
            traverseReverse(start);
            break;
        default:
            printf("not a valid input\n");
            break;
        }
    printf("want to continue? [y\\n] ");
    scanf(" %c", &conti);
    }
}

node *getReversed(node *start){
    node *temp = NULL;
    node *tempNode = NULL:
    node *prevNode = NULL;
    node *newList = NULL;
    temp = start;
    prevNode = start;
    do{
        tempNode = (node *)malloc(sizeof(node));
        if(newList == NULL){
            newList = tempNode;
        }
        tempNode->data = temp->data;
        temp = temp->next;
    }
    while(temp != start);
}

