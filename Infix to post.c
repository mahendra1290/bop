#include<stdio.h>
#include<string.h>
int max = 1000;
int infitopos(char [], char [], int len);
char pop(char stack[], int *top)
{
	if(*top >= 0)
	{
		return stack[(*top)--];
	}
	else
	{
		return '~';
	}
}
void push(char stack[], int *top, char data)
{
	if(*top < max-1)
	{
		stack[++(*top)]= data;
	}
}
int precedence(char m)
{
	int val;
	switch(m)
	{
		case '$': val  = 0;break;
		case '(': val  = 1;break;
		case ')': val  = 2;break;
		case '+': val  = 3;break;
		case '-': val  = 3;break;
		case '*': val  = 4;break;
		case '/': val  = 4;break;
	}
	return val;
}

int main()
{
	char str[100];
	printf("Enter your infix expression:");
	scanf("%s",str);
	int len = strlen(str);
	char postfix[len+2];
	infitopos(str, postfix, len);
	for(int i=0; i<len; i++)
		printf("%c",postfix[i]);
}
int infitopos( char str[], char postfix[], int len)
{
	int top = -1;
	int topp = -1;
	char stack[max];
	push(stack, &top, '$');
	for(int i=0; i<len; i++)
	{
		if(str[i] <= 57 && str[i] >= 48)
			push(postfix, &topp, str[i]);
		else
		{
			if(precedence(str[i]) > precedence(stack[top]) || str[i] == '('){
			    push(stack, &top, str[i]);
			}
			else{
			    while(precedence(str[i]) <= precedence(stack[top])){
			        char oper = pop(stack, &top);
				push(postfix, &topp, oper);
			    }
			    if(str[i] == ')'){
				pop(stack, &top);
			    }
			    else{
				push(stack, &top, str[i]);
			    }
			    
			}
		}
	}
	push(postfix, &topp, '\0');
}
