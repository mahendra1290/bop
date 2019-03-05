#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *ptr;
}node;
void deleteElemAfterVal(node *start, int val);
node *deleteElem(node *start,int elem);
node *deleteAtPos(node* start,int pos);
node *InsertBeforeElem(node *start, int elem,int toinsert);
node *InsertAtPos(node*start, int pos, int toinsert);
void InsertAfterElem(node*start, int elem, int toinsert);
void display(node *start);
node *create();

void display(node *start)
{
    node *temp = start;
    printf("data is = \n");
    while(temp!=NULL)
    {
        printf("data:%d  ptr = %d   fptr = %d\n",temp->data,temp, temp->ptr);
        temp = temp->ptr;
    }
}
node *create()
{
    int val;
    node *start =(node *)malloc(sizeof(node));
    node *temp = start;
    printf("Enter the element: ");
    scanf("%d",&val);
    node *ptemp;
    while(val!=-1)
    {
        temp->data = val;
        node *ptemp = (node *)malloc(sizeof(node));
        temp->ptr = ptemp;
        printf("Enter the element: ");
        scanf("%d", &val);
        if(val!=-1)
            temp = ptemp;
    }
    temp->ptr = NULL;
    free(ptemp);
    return start;
}
void InsertAfterElem(node *start, int num,int toinsert)
{
    node *temp = start;
    while(temp->data!=num)
    {
        temp = temp->ptr;
    }
    node *new_node =(node*)malloc(sizeof(node));
    new_node->ptr = temp->ptr;
    new_node->data =  toinsert;
    temp->ptr = new_node;
}
node* InsertBeforeElem(node *start, int num,int toinsert)
{
    node *temp = start;
    node* new_node = (node *)malloc(sizeof(node));
    node *req_ptr=NULL;
    while(temp->data!=num)
    {
        req_ptr = temp;
        temp = temp->ptr;
    }
    if(req_ptr ==NULL)
    {
        new_node->data = toinsert;
        new_node->ptr = start;
        return new_node;
    }
    new_node->data = toinsert;
    new_node->ptr = temp;
    req_ptr->ptr = new_node;
    return start;
}
node *InsertAtPos(node *start, int pos, int toinsert)
{
    node *temp = (node*)malloc(sizeof(node));
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = toinsert;
    temp = start;
    int temp_pos = pos;
    if(pos==1)
    {
        new_node->ptr = start;
        return new_node;
    }
    else
    {
        int temp_pos = pos-2;
        while(temp_pos--)
        {
            temp=temp->ptr;
        }
        if(temp->ptr==NULL)
        {
            temp->ptr = new_node;
            new_node->ptr= NULL;
        }
        else
        {
            new_node->ptr = temp->ptr;
            temp->ptr = new_node;
        }
    }
    return start;

}
node *deleteAtPos(node *start,int pos)
{
    node *temp = start,*temp2;
    if(pos==1)
    {
        temp=start->ptr;
        free(start);
        return temp;
    }
    else
    {
        pos = pos-2;
        while(pos--)
        {
            temp = temp->ptr;
        }
        temp2 = temp->ptr;
        temp->ptr = temp->ptr->ptr;
    }
    free(temp2);
    return start;
}
void deleteElemAfterVal(node *start,int val)
{
    node *temp =start,*temp2;
    while(temp->data!=val)
    {
        temp = temp->ptr;
    }
    temp2 = temp->ptr;
    temp->ptr=temp->ptr->ptr;
    free(temp2);
}
node *deleteElem(node *start, int elem)
{
    node *temp =start,*req_ptr =start;
    while(temp->data!=elem)
    {
        req_ptr = temp;
        temp=temp->ptr;
    }
    if(temp==start)
    {
        temp = temp->ptr;
        free(start);
        return temp;
    }
    else if(temp->ptr==NULL)
    {
        req_ptr->ptr = NULL;
        free(temp);
    }
    else
    {
        node*temp2 = req_ptr->ptr;
        req_ptr->ptr = temp->ptr;
        free(temp2);
    }
    return start;
}
int main()
{
    node *start = create();
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
           //     start = deleteElemBeforeVal(start, elem);
                break;
            case 7:
                printf("Enter the position you want to delete\n");
                scanf("%d",&pos);
                start = deleteAtPos(start, pos);
                break;
            case 8:
                display(start);
                break;
            case 10:
                check =0;
        }
    }
}

