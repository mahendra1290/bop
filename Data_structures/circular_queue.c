#include <stdio.h>

#define MAX_QUEUE_SIZE 5
int isFull(int queue[], int *front, int *rear);

int isEmpty(int queue[], int *front, int *rear);

void add(int queue[], int *front, int *rear, int val);

int delete(int queue[], int *front, int *rear);

int main(){
    int choice = 1;
    int elem;
    int queue[MAX_QUEUE_SIZE];
    int front = 0;
    int rear = 0;
    while (choice != 0){
        printf("1 > add\n");
        printf("2 > delete\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                //printf("enter elem: ");
                scanf("%d", &elem);
                add(queue, &front, &rear, elem);
                printf("front %d rear %d\n", front, rear);
                break;
            case 2:
                elem = delete(queue, &front, &rear);
                printf("deleted %d\n", elem);
                printf("front %d rear %d\n", front, rear);
                break;
        }
    }

}

int isFull(int queue[], int *front, int *rear){
    int newRear = (*rear+1)%MAX_QUEUE_SIZE;
    if (*front == newRear){
        return 1;
    }
    return 0;
}

int isEmpty(int queue[], int *front, int *rear){
    if (*front == *rear){
        return 1;
    }
    return 0;
}

void add(int queue[], int *front, int *rear, int val){
    if (!isFull(queue, front, rear)){
        *rear = (*rear+1)%MAX_QUEUE_SIZE;
        queue[*rear] = val;
    }
    else {
        fprintf(stderr, "queue is full\n");
    }
}

int delete(int queue[], int *front, int *rear){
    int elem = -99;
    if (!isEmpty(queue, front, rear)){
        *front = (*front+1)%MAX_QUEUE_SIZE;
        elem = queue[*front];
        queue[*front] = -1;
    }
    else {
        *front = 0;
        *rear  = 0;
        fprintf(stderr, "queue is empty\n");
    }
    return elem;
}

void push(int elem){
    if(top < MAXSIZE-1){
		stack[++top] = elem;
    }
    else{
		printf("Stack is full can't add more\n");
    }
}

int pop(){
   if(top > -1){
		return stack[top--];
   }
   else{
        printf("Stack is empty\n");
        return 99999;
   }
}