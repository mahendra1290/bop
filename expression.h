//library to convert infix expression into postfix and to solve postfix
//expressions

#include<stdio.h>
#include<string.h>
#define MAX 50

void intPush(int val, int stack[], int *top);
int  intPop(int stack[], int *top);
void charPush(char val, char stack[], int *top);
char charPop(char stack[], int *top);
int  getInfix(char str[]);
int  getPrecedence(char oper);
void toPostfix(char infix[], char postfix[], int infixLen);
int  evaluate(char str[], int len);

void charPush(char val, char stack[], int *top){
    if((*top) < MAX-1){
		stack[++(*top)] = val;
    }
    else{
		printf("stack is full can't add more...\n");
    }
}

char charPop(char stack[], int *top){
   if((*top) > -1){
		return stack[(*top)--];
   }
   else{
	    printf("stack is empty !...\n");
	    return '!';
   }
}

void intPush(int val, int stack[], int *top){
    if(*top < MAX-1){
		stack[++(*top)] = val;
    }
    else{
		printf("Stack is full can't add more\n");
    }
}

int intPop(int stack[], int *top){
   if((*top) > -1){
		return stack[(*top)--];
   }
   else{
        printf("Stack is empty\n");
        return 99999;
   }
}

int getInfix(char str[]){
	int left=0, right=0, len, i, num=0, oper=0;
    printf("enter the equation\n...");
    scanf("%s", str);
    len = strlen(str);
    for(i=0; i<len; i++){
		if(str[i] == '('){
		    left++;
		}
		else if(str[i] ==')'){
			right++;
		}
		else if(str[i] >= 48 && str[i] <= 57){
			num++;
		}
		else if(str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/'
				&& str[i] != '(' && str[i] != ')'){
			printf("invalid operator entered\n");
			return -1;
		}
		else{
			oper++;
		}
		if(right > left || left < right){
			printf("paranthesis error\n");
			return -1;
		}
		else if(num < oper){
			printf("operand error\n");
			return -1;
		}
    }
    printf("lef %d || righ %d || num %d || ope %d\n", left, right, num, oper);
    return len;
}

int getPrecedence(char oper){
    switch(oper){
		case '$':
			return 0;
		case ')':
			return 2;
		case '+':
		case '-':
			return 3;
		case '*':
		case '/':
			return 4;
		case '(':
			return 1;
		default:
			printf("invalid operator\n");
			return -1;
    }
}

void toPostfix(char infix[], char postfix[], int infixLen){
	char stack[MAX], operand;
	int top = -1, i, j, k;
	k = 0;
	charPush('$', stack, &top);
    for(i=0; i<infixLen; i++){
		if(infix[i] >= 48 && infix[i] <= 57){
			postfix[k++] = infix[i];
		}
		else{
			if((getPrecedence(stack[top]) < getPrecedence(infix[i])) || infix[i] == '('){
				charPush(infix[i], stack, &top);
			}
			else{
				while((getPrecedence(infix[i]) <= getPrecedence(stack[top])) && stack[top] != '$'){
					operand = charPop(stack, &top);
					postfix[k++] = operand;
				}
			    if(infix[i] == ')'){
					charPop(stack, &top);
			    }
			    else{
					charPush(infix[i], stack, &top);
			    }
			}
		}
    }
    operand = charPop(stack, &top);
	while(operand != '$' && operand != '!'){
		postfix[k++] = operand;
		operand = charPop(stack, &top);
	}
	postfix[k] = '\0';
}

int evaluate(char str[], int len){
	int stack[MAX];
	int top=-1;
    int i, result, val_1, val_2;
    for(i=0; i<len; i++){
		if(str[i] >= 48 && str[i] <= 57){
			intPush(str[i]-48, stack, &top);
		}
		else{
			val_1 = intPop(stack, &top);
		    val_2 = intPop(stack, &top);
			switch(str[i]){
				case '+':
					result = val_2 + val_1;
					break;
				case '-':
					result = val_2 - val_1;
					break;
				case '*':
					result = val_2 * val_1;
					break;
				case '/':
					result = val_2 / val_1;
					break;
			}
			intPush(result, stack, &top);
		}
    }
    result = intPop(stack, &top);
    return result;
}
