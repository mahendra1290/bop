/******************************
* Author      : Mahendra Suthar
* Date        : Sat May 11 17:12:24 2019
* ****************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

#define PRECTABLE_SIZE 18

typedef struct{
    char *oper;
    int prec;
}dict;

typedef struct {
    char **data;
    int top;    
}charStack;

dict *precTable = NULL;

charStack *createStack(int size);
void push(charStack *stack, char *val);
char *pop(charStack *stack);
char *showTop(charStack *stack);
dict *createPrecTable(char *filename);
int isLegalOper(char *c);
void convertInfixToPostfix(char *infix, char *postfix);

int main(){
    char *str = malloc(sizeof(char)*2);
    char *dest = malloc(sizeof(char)*2);
    char *temp;
    int choice;
    charStack *stack = createStack(MAX_STACK_SIZE);
    char infix[100];
    char postfix[100];
    precTable = createPrecTable("/media/maahi/Acer/Mahendra/Programms/Data_structures/ds_exam/prec.txt");
    printf("enter infix\n");
    scanf("%s", infix);
    convertInfixToPostfix(infix, postfix);
    printf("%s", postfix); 
    /*while (1){
        scanf("%s", str);
        if (isLegalOper(str)){
            printf("yes\n");
        }
        else{
            printf("no\n");
        } 
        printf("1.push\n2.pop\n");
        scanf("%d", &choice);
        if (choice == 1){
            printf("enter string: ");
            scanf("%s", str);
            //printf("main str %s\n", str);
            push(stack, str);
        }
        else if (choice == 2){
            temp = pop(stack);
            printf("popped %s\n", temp);
            printf("len is %d\n", strlen(temp));
            printf("enter to match : ");
            scanf("%s", str);
            if (!strcmp(temp, str)){
                printf("yes\n");
            }
            else {
                printf("no\n");
            }
        }
    }
    precTable = createPrecTable("prec.txt");
    for (int i=0; i<PRECTABLE_SIZE; i++){
        printf("oper - %s\n", precTable[i].oper);
        printf("prec - %d\n", precTable[i].prec);
    }*/

}

/* 
int validateInfix(char *expression, int len){
    int leftPran = 0;
    int rightPran = 0;
    int i = 0;
    int errorFlag = 0;
    for (i=0; i<len; i++){
        if (expression[i] == '('){
            leftPran++;
        }
        else if (expression[i] == ')'){
            rightPran++;
        }
        else if (!islegal(expression[i])){
            errorFlag = 1;
        }
        else if (islegal(expression[i])){
            if (i-1 >= 0){
                if (!isNumber(expression[i-1])){
                    errorFlag = 2;
                }
            }
            if (i+1 < len){
                if (!isNumber(expression[i+1])){
                    errorFlag = 2;
                }
            }
        }
        if (rightPran > leftPran){
            errorFlag = 3;
        }
    }

}

int isNumber(char c){
    if (c >= 48 || c <= 57){
        return 1;
    }
    return 0;
}*/

int isLegalOper(char *c){
    int i;
    char *legal[17] = {"+", "-", "*", "/", "%", ">>", "<<", ">",
                      "<", ">=", "<=", "==", "!=", "&&", "||", "(",
                      ")"};
    for (i=0; i<17; i++){
        if (!strcmp(c, legal[i])){
            return 1;
        }
    }
    return 0;
}



void parseExpression(char *str)
{
    int i, j;
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            while (str[j] != '\0' && str[j] == ' ')
            {
                j++;
            }
            str[i] = str[j];
            str[j] = ' ';
            if (str[i] == '\0')
            {
                break;
            }
        }
        i++;
        j++;
    }
}


charStack *createStack(int size){
    charStack *stack = malloc(sizeof(charStack));
    stack->data = malloc(sizeof(char*)*size);
    for (int i=0; i<size; i++){
        stack->data[i] = malloc(sizeof(char)*3);
        stack->data[i][2] = '\0';
    }
    stack->top  = -1;
    return stack;
}

void push(charStack *stack, char *val){
    //printf("%s", val);
    char *temp;
    if (stack->top < MAX_STACK_SIZE-1){
        strncpy(stack->data[++stack->top], val, 3);
    }
    else {
        fprintf(stderr, "stack full\n");
    }
}

char *pop(charStack *stack){
    if (stack->top > -1){
        return stack->data[stack->top--];
    }
    else {
        fprintf(stderr, "stack is empty\n");
        stack->data[0] = "$";
        return stack->data[0];
    }
}

char *showTop(charStack *stack){
    if (stack->top > -1){
        return stack->data[stack->top];
    }
    else {
        fprintf(stderr, "stack is empty\n");
        return NULL;
    }
}

int getPrecendance(char *oper){
    int size = PRECTABLE_SIZE;
    for (int i=0; i<size; i++){
        if (!strcmp(precTable[i].oper, oper)){
            return precTable[i].prec;
        }
    }
    return -1;
} 

dict *createPrecTable(char *filename){
    dict *table = malloc(sizeof(dict)*18);
    FILE *file = fopen(filename, "r");
    int len;
    char oper[3];
    int prec;
    fscanf(file, "%d", &len);
    for(int i=0; i<len; i++){
        fscanf(file, "%s", oper);
        fscanf(file, "%d", &prec);
        table[i].oper = malloc(3);
        strncpy(table[i].oper, oper, 3);
        table[i].prec = prec;
    }
    fclose(file);
    return table;
}
 
void convertInfixToPostfix(char *infix, char *postfix){
    int i=0;
    int j=0;
    int flag = 0;
    int k=0;
    char str[3];
    charStack *stack = NULL;
    stack = createStack(100);
    push(stack, "$");
    char *elem;
    printf("infix in %s\n", infix);
    while (infix[i] != '\0'){
        if (infix[i] >= 'a' && infix[i] <= 'z'){
            postfix[k] = infix[i];
            i++;
            k++;
        }
        else{
            if (infix[i+1] != '\0' && (infix[i+1] < 'a' || infix[i+1] > 'z') && (infix[i] != '(') && (infix[i] != ')')){
                str[0] = infix[i];
                str[1] = infix[i+1];
                str[2] = '\0';
                flag = 2;
            }
            else {
                str[0] = infix[i];
                str[1] = '\0';
                flag = 1;
            }
            if (infix[i] == ')'){
                elem = pop(stack);
                while (strcmp(elem, "(")){
                    for (int i=0; i<strlen(elem); i++){
                        postfix[k] = elem[i];
                        k++;
                    }
                    elem = pop(stack);
                }
            }
            else if (isLegalOper(str)){
                if (getPrecendance(str) > getPrecendance(showTop(stack)) || !strcmp(str, "(")){
                    push(stack, str);
                }
                else {
                    elem = pop(stack);
                    for (int i=0; i<strlen(elem); i++){
                        postfix[k] = elem[i];
                        k++;
                    }
                    push(stack, str);
                }
            }
            i += flag;
        }
    }
    elem = pop(stack);
    while (strcmp(elem, "$")){
        for (int i=0; i<strlen(elem); i++){
            postfix[k] = elem[i];
            k++;
        }
        elem = pop(stack);
    }
    postfix[k] = '\0';
}