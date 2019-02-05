#include<stdio.h>
#define MAXSIZE 5

int stack[MAXSIZE];
int top=-1;

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

int main(){
    char conti = 'y';
    int operation, elem;
    while(conti == 'y' || conti == 'Y'){
		printf("What you want to do ?\n");
	    printf("1. Push element in stack\n");
	    printf("2. Pop element from stack\n");
	    scanf("%d", &operation);
	    switch(operation){
		case 1:
			printf("enter element: ");
			scanf("%d", &elem);
			push(elem);
			break;
		case 2:
			elem = pop();
			if(elem != 99999){
				printf("popped element is %d\n", elem);
			}
			break;
		default:
			printf("not a valid operation\n");
			break;
	    }
	    printf("Want to continue [y/n]? ");
	    scanf(" %c", &conti);
    }
    elem = pop();
    printf("Stack items");
    while(elem != 99999){
		printf("%d\n", elem);
		elem = pop();
    }
    return 0;
}
