/*
all function of double linklist
created : 03/03/19
author  : mahendra
*/ 

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
node *reverse(node *start);
node *createReversed(node *start);

int main(){
    node *start;
    node *reversed;
    //linklistOper(start);
    start = createDoubLinklist(start);
    reversed = createReversed(start);
    traverse(reversed);
    traverseReverse(reversed);
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
    else{
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
                else{
                    printf("enter %d th data: ", i);
                    scanf("%d", &elem);
                    newNode->data = elem;
                    prevNode->next = newNode;
                    newNode->back = prevNode;
                    prevNode = newNode;
                    i++;
                }
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
    }
    prevNode->next = NULL;
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
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }   
}
//-------------------------------------------------------
void traverseReverse(node *start){
    node *temp = start;
    if(temp == NULL){
        printf("list is empty\n");
        return;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->back;
        }
        printf("\n");
    }
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
    while(temp->next != NULL && i < position){
        temp = temp->next;
        i++;
    }
    if(temp->next == NULL && position > i){
        printf("POSITION ERROR\n");
        printf("insertion operation failed\n");
        return newStart;
    }
    newNode = (node *)malloc(sizeof(node));
    newNode->data = newValue;
    
    if(position == 1){
        newNode->back = NULL;
        newNode->next = temp;
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
    while(temp->next != NULL && temp->data != value){
        temp = temp->next;
    }
    if(temp->next == NULL && temp->data != value){
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
        printf("[6] reverse\n");
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
        case 6:
            start = reverse(start);
            break;
        default:
            printf("not a valid input\n");
            break;
        }
    printf("want to continue? [y\\n] ");
    scanf(" %c", &conti);
    }
}
//--------------------------------------------------
node *reverse(node *start){
    node *newStart = NULL;
    node *current  = NULL;
    node *nextNode = NULL;
    current = start;
    while(current != NULL){
        nextNode = current->next;
        current->next = current->back;
        current->back = nextNode;
        newStart = current;
        current = nextNode;
    }
    return newStart;
}
//----------------------------------------------------
node *createReversed(node *start){
     node *temp     = NULL;
     node *previous = NULL;
     node *newNode  = NULL;
     temp = start;
     while(temp != NULL){
        newNode = (node *)malloc(sizeof(node));
        newNode->data = temp->data;
        newNode->next = previous;
        if(previous != NULL){
            previous->back = newNode;
        }
        previous = newNode;
        temp = temp->next;
     }
     return newNode;
}
