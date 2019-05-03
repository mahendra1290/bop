#include <stdio.h>

#define MAX_QUEUE_SIZE 100

#define MAX_STACK_SIZE 100

int isFull(int queue[], int *front, int *rear);

int isEmpty(int queue[], int *front, int *rear);

void add(int queue[], int *front, int *rear, int val);

int delete(int queue[], int *front, int *rear);

void pushInt(int stack[], int *top, int val);

int popInt(int stack[], int *top);

void splitStack(int stack[], int *top);

int main(){
    int stack[MAX_STACK_SIZE];
    int top = -1;
    int elem = 0;
    for (int i = 0; i<20; i++){
        scanf("%d", &elem);
        pushInt(stack, &top, elem);
    }
    for (int i=0; i<=top; i++){
        printf("%d ", stack[i]);
    }
    splitStack(stack, &top);
    for (int i=0; i<=top; i++){
        printf("%d ", stack[i]);
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
    int elem = -99999;
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

void pushInt(int stack[], int *top, int val)
{
	if (*top < MAX_STACK_SIZE - 1)
	{
		stack[++(*top)] = val;
	}
	else
	{
		printf("Stack is full can't add more\n");
	}
}

int popInt(int stack[], int *top)
{
	if ((*top) > -1)
	{
		return stack[(*top)--];
	}
	else
	{
		printf("Stack is empty\n");
		return -99999;
	}
}

void splitStack(int stack[], int *top){
    int queue[MAX_QUEUE_SIZE];
    int front = 0;
    int rear  = 0;
    int elem = 0;
    int neg = 0;
    elem = popInt(stack, top);
    while (elem != -99999){
        if (elem < 0){
            neg++;
        }
        add(queue, &front, &rear, elem);
        elem = popInt(stack, top);
    }
    while (neg){
        elem = delete(queue, &front, &rear);
        if (elem < 0){
            pushInt(stack, top, elem);
            neg--;
        }
        else {
            add(queue, &front, &rear, elem);
        }
    }
    elem = delete(queue, &front, &rear);
    while (elem != -99999){
        pushInt(stack, top, elem);
        elem = delete(queue, &front, &rear);
    }
}