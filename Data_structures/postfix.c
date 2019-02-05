#include<stdio.h>
#include<string.h>
#define MAXSIZE 50

int evaluate(char str[], int len);
void push(int elem);
int pop();

int stack[MAXSIZE];
int top=-1;


int main(){
	int i, len, ans;
    char str[100];
    while(1){
		printf("enter postfix expression...enter q to exit\n");
        scanf("%s", str);
        len = strlen(str);
        if(str[0] == 'q'){
			break;
        }
        ans = evaluate(str, len);
        printf("ans %d\n", ans);
    }
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

int evaluate(char str[], int len){
    int i, result, val_1, val_2;
    for(i=0; i<len; i++){
		if(str[i] >= 48 && str[i] <= 57){
			push(str[i]-48);
		}
		else{
			val_1 = pop();
		    val_2 = pop();
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
			push(result);
		}
    }
    result = pop();
    return result;
}

