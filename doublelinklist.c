#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* fptr;
    struct node* bptr;

}node;
node * deleteElemBeforeVal(node *start, int val);
void deleteElemAfterVal(node *start, int val);
node *deleteElem(node *start,int elem);
node *deleteAtPos(node* start,int pos);
node *InsertBeforeElem(node *start, int elem,int toinsert);
node *InsertAtPos(node*start, int pos, int toinsert);
void InsertAfterElem(node*start, int elem, int toinsert);
void displayBack(node *start);
void display(node *start);
node * createDLL();
node * createDLL()
{
    int  val;
    node *start = (node*)malloc(sizeof(node));
    node *temp=start, *reqptr = NULL;
    start->bptr = NULL;
    printf("Input will be taken untill -1 is entered...\n");
    while(val!=-1)
    {
        temp->bptr = reqptr;
        printf("Enter the value :");
        scanf("%d",&val);
        node *new_node = (node*)malloc(sizeof(node));
        temp->data = val;
        temp->fptr = new_node;
        reqptr = temp;
        temp = new_node;
    }
    reqptr->bptr->fptr = NULL;
    return start;

}

void displayBack(node *start)
{
    node *temp= start;
    while(temp->fptr!=NULL)
    {
        temp = temp->fptr;
    }
    while(temp!=NULL)
    {
        printf("\nval =%d ..bptr = %d.. fptr = %d\n",temp->data, temp->bptr,temp->fptr);
        temp = temp->bptr;
    }
}

void display(node *start)
{
    node*temp = start;
    do
    {
        printf("\nval =%d ..bptr = %d.. fptr = %d\n",temp->data, temp->bptr,temp->fptr);
        temp = temp->fptr;
    }
    while(temp!=0);
}

void InsertAfterElem(node*start, int elem, int toinsert)
{
    node *temp = start;
    while(temp->data!=elem)
    {
        temp = temp->fptr;
    }
    node *new_node = (node*)malloc(sizeof(node));
    new_node->bptr = temp;
    new_node->data = toinsert;
    new_node->fptr = temp->fptr;
    if(temp->fptr==NULL)
    {
        temp->fptr = new_node;
        return;
    }
    temp->fptr->bptr = new_node;
    temp->fptr = new_node;
}
node *InsertAtPos(node*start, int pos, int toinsert)
{
    node *temp=start;
    int temp_pos = pos-2;
    node *new_node = (node*)malloc(sizeof(node));
    if(pos==1)
    {
        new_node->bptr = NULL;
        new_node->data = toinsert;
        new_node->fptr = start;
        start->bptr = new_node;
        return new_node;
    }
    else
    {
        while(temp_pos--)
        {
            temp = temp->fptr;
        }
        new_node->data = toinsert;
        new_node->bptr = temp;
        new_node->fptr = temp->fptr;
        if(temp->fptr==NULL)
        {
            temp->fptr = new_node;
            return start;
        }
        temp->fptr->bptr = new_node;
        temp->fptr = new_node;
        return start;
    }
}
node *InsertBeforeElem(node *start, int elem,int toinsert)
{
    node *temp = start;
    node *new_node = (node*)malloc(sizeof(node));
    while(temp->data!=elem)
    {
        temp = temp->fptr;
    }
    if(temp==start)
    {
        new_node->data = toinsert;
        new_node->fptr=start;
        start->bptr = new_node;
        new_node->bptr = NULL;
    }
    else
    {
        new_node->data = toinsert;
        new_node->fptr = temp;
        new_node->bptr = temp->bptr;
        (temp->bptr)->fptr = new_node;
        temp->bptr = new_node;
        return start;
    }
}

node *deleteAtPos(node* start,int pos)
{
    node *temp =start;
    int temp_pos = pos-1;
    if(pos==1)
    {
        temp->fptr->bptr=NULL;
        return temp->fptr;
    }
    else
    {
        while(temp_pos--)
        {
            temp = temp->fptr;
        }
        if(temp->fptr==NULL)
        {
            temp->bptr->fptr = NULL;
        }
        else
        {
            temp->bptr->fptr = temp->fptr;
            temp->fptr->bptr = temp->bptr;
        }
        return start;
    }
}
node *deleteElem(node *start,int elem)
{
    node* temp = start;
    while(temp->data!=elem)
    {
        temp = temp->fptr;
    }
    if(temp==start)
    {
        temp->fptr->bptr = NULL;
        return temp->fptr;
    }
    else if(temp->fptr==NULL)
    {
        temp->bptr->fptr=NULL;
    }
    else
    {
        temp->bptr->fptr = temp->fptr;
        temp->fptr->bptr = temp->bptr;
    }
    return start;
}

void deleteElemAfterVal(node *start, int val)
{
    node *temp = start;
    while(temp->data!=val)
    {
        temp = temp->fptr;
    }
    if((temp->fptr)->fptr==NULL)
    {
        temp->fptr= NULL;

    }
    else
    {
        temp->fptr = temp->fptr->fptr;
        temp->fptr->bptr = temp;
    }
}
node * deleteElemBeforeVal(node *start, int val)
{
    node *temp = start;
    while(temp->data!=val)
    {
        temp  = temp->fptr;
    }
    if(temp->bptr==start)
    {
        temp->bptr = NULL;
        free(start);
        return temp;

    }
    else
    {
        node *temp_ptr=temp->bptr;
        temp->bptr = (temp_ptr)->bptr;
        (temp_ptr)->fptr = temp;
        free(temp_ptr);
        return start;
    }


}
int main()
{
    node *start = createDLL();
    int check =1;
    int elem, toinsert,pos;
    while(check)
    {
        printf("Enter the operation\n");
        printf("1 : Insert before an Element\n");
        printf("2 : Insert at a particular position\n");
        printf("3: Insert after an element\n");
        printf("4: Delete an element\n");
        printf("5: Delete after an element\n");
        printf("6: Delete before an element\n");
        printf("7: Delete at a position\n");
        printf("8: Display from front\n");
        printf("9: Display from back\n");
        printf("10 : Exit");
        int ope;
        scanf("%d",&ope);

        switch(ope)
        {
            case 1:
                printf("Enter the element before you want to insert and the value you want to insert\n");
                scanf("%d%d",&elem,&toinsert);
                start = InsertBeforeElem(start, elem,toinsert);
                break;
            case 2:
                printf("Enter the position you want to insert and the value you want to insert\n");
                scanf("%d%d",&pos,&toinsert);
                start = InsertAtPos(start, pos, toinsert);
                break;
            case 3:
                printf("Enter the element after you want to insert and the value you want to insert\n");
                scanf("%d%d",&elem,&toinsert);
                InsertAfterElem(start, elem,toinsert);
                break;
            case 4:
                printf("Enter the element you want to delete\n");
                scanf("%d",&elem);
                start = deleteElem(start,elem);
                break;
            case 5:
                printf("Enter the element after you want to delete\n");
                scanf("%d",&elem);
                deleteElemAfterVal(start, elem);
                break;
            case 6:
                printf("Enter the before after you want to delete\n");
                scanf("%d",&elem);
                start = deleteElemBeforeVal(start, elem);
                break;
            case 7:
                printf("Enter the position you want to delete\n");
                scanf("%d",&pos);
                start = deleteAtPos(start, pos);
                break;
            case 8:
                display(start);
                break;
            case 9:
                displayBack(start);
                break;
            case 10:
                check =0;
        }
    }
}
