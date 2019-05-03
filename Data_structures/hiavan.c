#include<stdio.h>
#include<string.h>
typedef struct node{
    int data;
    struct node * ptr;
}node ;


void display(node *start){
    node *temp = start;
    while (temp){
        printf("%d ", temp->data);
        temp = temp->ptr;
    }
}


node *reverse(node *temp){
    node *next = NULL;
    if (temp->ptr != NULL){
        next = temp->ptr;
        node *head = reverse(next);
        next->ptr = temp;
        temp->ptr = NULL;
        return head;
    }
    else {
        return temp; 
    }
}

node* reversalRecursivleyLL(node *temp)
{
    if(temp->ptr==NULL)
    {
        return temp;
    }
    else
    {
        node * newnode = reversalRecursivleyLL(temp->ptr);
        (temp->ptr)->ptr = temp;
        temp->ptr = NULL;
        return newnode;
    }
}

node *create()
{
    node *newnode,*temp=NULL,*returnptr;
    int ope, val;
    do
    {
        newnode = (node*)malloc(sizeof(node));
        if(temp!=NULL)
            temp->ptr = newnode;
        else
            returnptr = newnode;
        printf("enter the value\n");
        scanf("%d", &val);
        newnode->data = val;
        printf("enter 1 to continue and 0 to exit\n");
        scanf("%d", &ope);
        temp = newnode;
    }
    while(ope);
    temp->ptr =NULL;
    return returnptr;
}

int main()
{
    node *start = create();
    display(start);
    node *head =NULL;
    //display(start);
    node *temp = start->ptr;
    start = reversalRecursivleyLL(start);
    display(start);
    //if(head==NULL)
   //     printf("head is NULL");
    //printf("head = %d",head->data);
    //display(head);
}