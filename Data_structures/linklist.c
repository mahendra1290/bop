#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *ptr;
}node;

void displayLinklist(node *start, int len);
node *createLinkList(int len);

int main(){
	int i, len, data;
	printf("enter length of list\n");
	scanf("%d", &len);
    node *start = createLinkList(len);
    displayLinklist(start, len+5);
}

void displayLinklist(node *start, int len){
    node *temp = start;
    int i=0;
    do{
        printf("data -> %d\n", temp->data);
        temp = temp->ptr;
    }
    while(i++ < len);
}

node *createLinkList(int len){
    int i=0, elem;
    node *temp;
    node *start = (node*)malloc(sizeof(node));
    node previous;
    previous.ptr = start;
    printf("enter %d th data: ", i+1);
    scanf("%d", &elem);
    start->data = elem;
    while(++i<len){
        temp = (node*)malloc(sizeof(node));
        (previous.ptr)->ptr = temp;
        previous.ptr = temp;
        printf("enter %d th data: ", i+1);
        scanf("%d", &elem);
        temp->data = elem;
    }
    temp->ptr = start;
    return start;
}
