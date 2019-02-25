#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *ptr;
}node;

node *createLinkList(int len);

int main(){
	int i, len, data;
	printf("enter length of list\n");
	scanf("%d", &len);
    node *start = createLinkList(len);
    for(i=0; i<=len; i++){
        printf("%d\n", (previous.ptr)->data);
        previous.ptr = (previous.ptr)->ptr;
    }
    return 0;
}

node *createLinkList(int len){
    node start, previous;
    previous.ptr = &start;
    for(i=0; i<len; i++){
        node *temp = (node*)malloc(sizeof(node));
        (previous.ptr)->ptr = temp;
        previous.ptr = temp;
    }
    return &start;
}
