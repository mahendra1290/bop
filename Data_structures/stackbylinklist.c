#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *ptr;
}node;

typedef struct intStack{
    struct node *top;
}intStack;

void push(intStack *stack, int value);
int pop(intStack *stack);

int main(){
    intStack *stack;
    stack->top = NULL;
    int choice;
    int value;
    while(1){
        printf("[1] push\n");
        printf("[2] pop\n");
        scanf("%d", &choice);
        if(choice == 1){
            printf("enter the value: ");
            scanf("%d", &value);
            push(stack, value);
        }
        else{
            value = pop(stack);
            printf("popped value %d\n", value);
        }
    }
}

void push(intStack *stack, int value){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->ptr = stack->top;
    stack->top = newNode;
}

int pop(intStack *stack){
    int value;
    node *toDelete;
    if(stack->top == NULL){
        printf("stack is empty can't pop\n");
        return 999999;
    }
    toDelete = stack->top;
    value = (stack->top)->data;
    stack->top = (stack->top)->ptr;
    free(toDelete);
    return value;
}
