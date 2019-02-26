#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *ptr;
}node;

void displayLinklist(node *start);
node *createLinkList();
int maxInList(node *start);

int main(){
	printf("enter -1 to stop entering data and display\n");
    node *start = createLinkList();
    displayLinklist(start);
    int maxx = maxInList(start);
    printf("max in list %d\n", maxx);
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

int maxInList(node* start){
    node *temp = start;
    int maxx = temp->data;
    while(temp->data != -1){
        if(temp->data > maxx){
            maxx = temp->data;
        }
        temp = temp->ptr;
    }
    return maxx;
}
