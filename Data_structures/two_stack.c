/******************************
 * Author      : Mahendra Suthar
 * Date        : 19/04/2019
 * Description : program to implement two stack in single array
 * ****************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 10

typedef struct {
    int *arr;
    int top1;
    int top2;
    int size;
} intStack;

void push(intStack *stack, int stackNo, int val);

int pop(intStack *stack, int stackNo);

intStack *createStack();

void print(intStack *stack, int stackNo);

int main(){
    intStack *stack;
    stack = createStack();
    int data = 0;
    scanf("%d", &data);
    do {
        push(stack, 0, data);
        scanf("%d", &data);
    }while(data != -1);
    data = 0;
    scanf("%d", &data);
    do {
        push(stack, 1, data);
        scanf("%d", &data);
    }while(data != -1);
    print(stack, 0);
    printf("\n");
    print(stack, 1);
    
    return 0;
}
//returns integer stack
intStack *createStack(){
    intStack *stack = malloc(sizeof(intStack));
    stack->arr = malloc(sizeof(int)*SIZE);
    stack->top1 = -1;
    stack->top2 = SIZE;
    stack->size = SIZE;
}
//push an element in stack parameter stackNo to select stack
//doubles stack size when overflow
void push(intStack *stack, int stackNo, int val){
    if (stack->top1 != stack->top2-1){
        if (stackNo == 0){
            stack->arr[++stack->top1] = val;
        }
        else{
            stack->arr[--stack->top2] = val;
        }
    }
    else{
        stack->arr = realloc(stack->arr, (stack->size*2*sizeof(int)));
        for (int i=stack->size-1; i>= stack->top2; i--){
            stack->arr[i+stack->size] = stack->arr[i];
        }
        stack->top2 = stack->size + stack->top2;
        stack->size = stack->size*2;
        push(stack, stackNo, val);
    }
}
//return top element of stack 
//stackNo to select from which stack to pop
int pop(intStack *stack, int stackNo){
    if (stackNo == 0){
        if (stack->top1 > -1){
            return stack->arr[stack->top1--];
        }
        else{
            //fprintf(stderr, "stack is empty can't pop\n");
            return INT_MIN;
        }
    }
    else
    {
        if (stack->top2 < stack->size){
            return stack->arr[stack->top2++];
        }
        else{
            //fprintf(stderr, "stack is empty can't pop\n");
            return INT_MIN;
        }
    }
}
//prints stack data
void print(intStack *stack, int stackNo){
    int elem;
    if (stackNo == 0){
        elem = pop(stack, 0);
        while(elem != INT_MIN){
            printf("%d ", elem);
            elem = pop(stack, 0);
        }
    }
    else{
        elem = pop(stack, 1);
        while(elem != INT_MIN){
            printf("%d ", elem);
            elem = pop(stack, 1);
        }
    }
}

