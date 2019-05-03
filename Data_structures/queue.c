
#include <stdio.h>

#include <limits.h>

#define MAX_QUEUE_SIZE 5

int isFullQ(int queue[], int *front, int *rear);

int isEmptyQ(int queue[], int *front, int *rear);

void addQ(int queue[], int *front, int *rear, int val);

int deleteQ(int queue[], int *front, int *rear);

void compactQ(int queue[], int *front, int *rear);

int main(){
    int queue[MAX_QUEUE_SIZE];
    int front = -1;
    int rear  = -1;
    int choice = 0;
    int elem = 0;
    int temp = 0.9*MAX_QUEUE_SIZE;
    printf("%d\n", temp);
    while (choice != -1){
        printf("==========\n");
        printf("1. add\n");
        printf("2. delete\n");
        printf("==========\n");
        scanf("%d", &choice);
        printf("front %d rear %d\n", front, rear);
        switch (choice){
            case 1:
                scanf("%d", &elem);
                addQ(queue, &front, &rear, elem);
                printf("front %d rear %d\n", front, rear);
                break;
            case 2:
                elem = deleteQ(queue, &front, &rear);
                printf("front %d rear %d\n", front, rear);
                printf("deleted %d\n", elem);
                break;
        }
    }
    
    return 0;
}
//returns 1 if queue is full and 0 if not full
int isFullQ(int queue[], int *front, int *rear){
    if (*rear == MAX_QUEUE_SIZE-1){
        return 1;
    }
    return 0;
}
//returns 1 if queue is empty and 0 if not empty
int isEmptyQ(int queue[], int *front, int *rear){
    if (*rear == -1){
        return 1;
    }
    return 0;
}
//add an element to queue
void addQ(int queue[], int *front, int *rear, int val){
    if (!isFullQ(queue, front, rear)){
        if (*front == -1){
            (*front)++;
        }
        queue[++(*rear)] = val;
        int temp = 0.9*MAX_QUEUE_SIZE;
        if (*rear >= temp){
            compactQ(queue, front, rear);
        }
    }
    else{
        fprintf(stderr, "queue is full can't add more\n");
    }
}
//delete an element from queue 
int deleteQ(int queue[], int *front, int *rear){
    int elem = INT_MIN;
    if (!isEmptyQ(queue, front, rear)){
        elem = queue[(*front)++];
        if (*front > *rear){
            *front = -1;
            *rear  = -1;
        }
        int temp = 0.9*MAX_QUEUE_SIZE;
        if (*rear >= temp){
            compactQ(queue, front, rear);
        }
    }
    else {
        fprintf(stderr, "queue is empty\n");
    }
    return elem;
}
//shift the element 
void compactQ(int queue[], int *front, int *rear){
    int j = *front;
    if (j > 0){
        for (int i=(*front); i<=(*rear); i++){
            queue[i-j] = queue[i];
        }
        *rear = *rear - j;
        *front = 0;
    }
}

