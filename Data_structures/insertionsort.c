#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node *nextPtr;
}node;

node *createArray(int len);
void printArray(node *arr);
void insertionSort(node **arr);

int main(){
     int len;
     node *array;
     printf("how many values you want to enter: ");
     scanf("%d", &len);
     array = createArray(len);
     printArray(array);
     insertionSort(&array);
     printArray(array);
}

node *createArray(int len){
    int termsCount = 0;
    int elem;
    node *newValue = NULL;
    node *start    = NULL;
    node *previous = NULL;
    if(start == NULL){
        start = (node *)malloc(sizeof(node));
    }
    if(len == 0){
        printf("empty array created\n");
        return start;
    }
    previous = start;
    printf("enter data in array\n>> ");
    scanf("%d", &elem);
    start->data = elem;
    while(termsCount < len-1){
        scanf("%d", &elem);
        newValue = (node *)malloc(sizeof(node));
        newValue->data = elem;
        previous->nextPtr = newValue;
        previous = newValue;
        termsCount++; 
    }
    newValue->nextPtr = NULL;
    return start;
}
//----------------------------------------------------
void printArray(node *arr){
    node *temp;
    temp = arr;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->nextPtr;
    }
    printf("\n");
}

void insertionSort(node **arr){
    node *temp = NULL;
    node *staticNode = NULL;
    node *smallest = NULL;
    node *excStatic = NULL;
    node *excNode = NULL;
    node *prevNode = NULL;
    node *previous = NULL;
    staticNode = (node *)malloc(sizeof(node));
    int min;
    staticNode->nextPtr = *arr;
    while((staticNode->nextPtr)->nextPtr != NULL){
        temp = staticNode->nextPtr;
        printf("stat %d\n", (staticNode->nextPtr)->data);
        min = temp->data;
        while(temp->nextPtr != NULL){
            if((temp->nextPtr)->data < min){
                min = (temp->nextPtr)->data;
                smallest = temp;
            }
            printf("exch %d\n", (temp->nextPtr)->data);
            temp = temp->nextPtr;
        }
        printf("min %d\n", min);
        //printArray(*arr);
        if(smallest != NULL){
            excStatic  = staticNode->nextPtr;
            excNode    = smallest->nextPtr;
            staticNode->nextPtr = excNode;
            excStatic->nextPtr = excNode->nextPtr;
            temp->nextPtr = excStatic;
            excNode->nextPtr = excStatic->nextPtr;
        }
        else{
            staticNode = staticNode->nextPtr;
        }
    } 
}
