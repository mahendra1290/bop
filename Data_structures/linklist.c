#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *ptr;
}node;

void displayLinklist(node *start);
node *createLinkList();

int main(){
	int i, len, data;
	printf("enter length of list\n");
	scanf("%d", &len);
    node *start = createLinkList();
    displayLinklist(start);
}

void displayLinklist(node *start){
    node *temp = start;
    printf("data in linklist...\n");
    while(temp->data != -1){
        printf("%d\n", temp->data);
        temp = temp->ptr;
    }
}

node *createLinkList(){
    int i=1, elem;
    node *temp;
    node *start = (node*)malloc(sizeof(node));
    node previous;
    previous.ptr = start;
    do{
        printf("enter %d th data: ", i++);
        scanf("%d", &elem);
        (previous.ptr)->data = elem;
        temp = (node*)malloc(sizeof(node));
        (previous.ptr)->ptr = temp;
        previous.ptr = temp;
    }
    while(elem != -1);
    temp->ptr = start;
    return start;
}
