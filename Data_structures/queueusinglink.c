#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *ptr;
}node;

typedef struct queue{
    struct node *front;
    struct node *rear;
}queue;

void insertElem(queue *queA);
int  deleteElem(queue *queA);
void printQueue(queue *queA);

int main(){
    queue *que;
    que = (queue *)malloc(sizeof(queue));
    int i=0;
    for(i=0; i<10; i++){
        insertElem(que);
    }
    for(i=0; i<8; i++){
        int elem = deleteElem(que);
        printf("%d \n", elem);
    }
    printQueue(que);
    for(i=0; i<10; i++){
        insertElem(que);
    }
    for(i=0; i<12; i++){
        int elem = deleteElem(que);
        printf("%d \n", elem);
    }
    printQueue(que);
}

void insertElem(queue *que){
    if(que == NULL){
        que = (queue *)malloc(sizeof(queue));
    }
    int elem;
    node *newNode;
    printf("enter value: ");
    scanf("%d", &elem);
    newNode = (node *)malloc(sizeof(node));
    newNode->data = elem;
    if(que->front == NULL && que->rear == NULL){
        que->front = newNode;
    }
    else{
        (que->rear)->ptr = newNode;
    }
    que->rear  = newNode;
}

int deleteElem(queue *que){
    int elem;
    node *toDelete;
    if(que->front == NULL){
        printf("queue is empty can't delete\n");
        return 9999;
    }
    elem = (que->front)->data;
    toDelete   = que->front;
    que->front = (que->front)->ptr;
    if(que->front == NULL){
        que->rear = NULL;
    }
    free(toDelete);  
    return elem;
}

void printQueue(queue *que){
    node *temp;
    temp = que->front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->ptr;
    }
}



