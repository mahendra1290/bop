#include<stdio.h>
#define SIZE 50
#include<string.h>

char stack[SIZE];
int top = -1;

void push(char elem){
    if(top < SIZE-1){
		stack[++top] = elem;
    }
    else{
		printf("Stack is full can't add more...\n");
    }
}

char pop(){
   if(top > -1){
		return stack[top--];
   }
   else{
	    return ' ';
   }
}

int main(){
	int i, len, mid;
	char str[100];
	char temp;
	printf("enter string to check and q to exit..\n");
	while(1){
		scanf("%s", str);
		len = strlen(str);
		if((str[0] == 'q' || str[0] == 'Q') && len == 1){
			printf("Good bye..\n");
			break;
		}
		mid = len/2;
		for(i=0; i<mid; i++){
			push(str[len-1-i]);
		}
		for(i=0; i<mid; i++){
			temp = pop();
			if(temp != str[mid-1-i]){
				break;
			}
		}
		if(i == mid){
			printf("string is palindromic...\n");
		}
		else{
			printf("String is not palindromic...\n");
		}
		while(pop() != ' '){
			continue;
		}
	}
	return 0;
}
