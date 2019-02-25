//library to convert infix expression into postfix and to solve postfix
//expressions

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

void pushInt(int val, int stack[], int *top);
int  popInt(int stack[], int *top);
void pushChar(char val, char stack[], int *top);
char popChar(char stack[], int *top);
int  getInfix(char str[]);
int  getPrecedence(char oper);
void convertInfixToPostfix(char infix[], char postfix[], int infixLen);
int  solvePostfix(char str[], int len);
int  validateInfix(char infix[], int len);
int  getRandom(int start, int end);
char *makeInfix();

void pushChar(char val, char stack[], int *top){
    if((*top) < MAX-1){
		stack[++(*top)] = val;
    }
    else{
		printf("stack is full can't add more...\n");
    }
}

char popChar(char stack[], int *top){
   if((*top) > -1){
		return stack[(*top)--];
   }
   else{
	    printf("stack is empty !...\n");
	    return '!';
   }
}

void pushInt(int val, int stack[], int *top){
    if(*top < MAX-1){
		stack[++(*top)] = val;
    }
    else{
		printf("Stack is full can't add more\n");
    }
}

int popInt(int stack[], int *top){
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
    printf("enter the equation...\n");
    scanf("%s", str);
    len = strlen(str);
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

void convertInfixToPostfix(char infix[], char postfix[], int infixLen){
	char stack[MAX], operand;
	int top = -1, i, j, k;
	k = 0;
	pushChar('$', stack, &top);
    for(i=0; i<infixLen; i++){
		if(infix[i] >= 48 && infix[i] <= 57){
			postfix[k++] = infix[i];
		}
		else{
			if((getPrecedence(stack[top]) < getPrecedence(infix[i])) || infix[i] == '('){
				pushChar(infix[i], stack, &top);
			}
			else{
				while((getPrecedence(infix[i]) <= getPrecedence(stack[top])) && stack[top] != '$'){
					operand = popChar(stack, &top);
					postfix[k++] = operand;
				}
			    if(infix[i] == ')'){
					popChar(stack, &top);
			    }
			    else{
					pushChar(infix[i], stack, &top);
			    }
			}
		}
    }
    operand = popChar(stack, &top);
	while(operand != '$' && operand != '!'){
		postfix[k++] = operand;
		operand = popChar(stack, &top);
	}
	postfix[k] = '\0';
}

int solvePostfix(char str[], int len){
	int stack[MAX];
	int top=-1;
    int i, result, val_1, val_2;
    for(i=0; i<len; i++){
		if(str[i] >= 48 && str[i] <= 57){
			pushInt(str[i]-48, stack, &top);
		}
		else{
			val_1 = popInt(stack, &top);
		    val_2 = popInt(stack, &top);
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
			pushInt(result, stack, &top);
		}
    }
    result = popInt(stack, &top);
    return result;
}

int validateInfix(char infix[], int len){
	///validate infix expression
    int i, j, left, right, oper, numb, valid;
    valid = 1;
    left  = 0;
    right = 0;
    oper  = 0;
    numb  = 0;
        for(i=0; i<len; i++){
			switch(infix[i]){
				case '(':
					left++;
					break;
				case ')':
					right++;
					break;
				case '+':
				case '-':
				case '*':
				case '/':
					oper++;
					break;
				default:
					if(infix[i] >= 48 && infix[i] <= 57){
						numb++;
					}
					else{
						printf("ERROR : ! invalid character entered...\n");
						valid = 0;
						return valid;
					}
					break;
			}
			if(right > left){
				printf("ERROR: ! parenthesis does not match...\n");
				valid = 0;
				return valid;
			}
    }
    if(numb <= oper || (numb-oper)!=1){
		printf("ERROR: ! operator ,operand mismatch...\n");
		valid = 0;
		return valid;
	}
    return valid;
}

int getRandom(int start, int end){
	///returns random number between start and end both included
    int random = (rand() % (end-start+1)) + start;
    return random;
}

char *makeInfix(){
	char operators[4] = {'+', '-', '*', '/'};
	char   numbers[9] = {'1', '2', '3', '4', '5' ,'6', '7', '8', '9'};
    char *infix = (char *)malloc(MAX);
    int oddLength, i, brackCount;
    oddLength  = 2*getRandom(3, MAX/2)+1;
    brackCount = getRandom(0, ((oddLength/2)-1));
    printf("brackets %d\n", brackCount);
    for(i=0; i<oddLength; i++){
		if(i%2 == 0){
			infix[i] = numbers[getRandom(0, 8)];
		}
		else{
			infix[i] = operators[getRandom(0, 3)];
		}
    }
    infix[i] = '\0';
    return infix;
}
