#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *ptr;
}node;

node *createLinklist();
void traverse(node *start);
node *insertAtPlace(node *start, int place, int newValue);
void insertAfter(node *start, int value, int newValue);
node *insertBefore(node *start, int value, int newValue);
void deleteAfter(node *start, int value);
node *deleteNode(node *start, int value);
node *deleteNodeAtPos(node *start, int position);
void linklistOper(node *start);
node *reverse(node *start);
node *createReversed(node *start);
void deleteOddNode(node **start);
node *mergeLinklist(node *first, node *second);
void splitIntoFour(node **first, node **second, node **three, node **four, node *start);

int main(){
    node *first = NULL;
    node *second = NULL;
    node *third = NULL;
    node *fourth = NULL;
    node *start;
    //linklistOper(start);
    start  = createLinklist();
    splitIntoFour(&first, &second, &third, &fourth, start);
    traverse(first);
    traverse(second);
    traverse(third);
    traverse(fourth);
    //reversed = createReversed(start);
    //traverse(reversed);
}
//----------------------------------------------------------- 
void traverse(node *start){
    node *temp = start;
    if(temp == NULL){
        printf("list is empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->ptr;
    }
    printf("\n");
}
//----------------------------------------------------------- 
node *createLinklist(){
    int i=1, elem;
    int mode  = 1;
    int count = 0;
    char conti = 'y';
    node *temp;
    node *start = (node*)malloc(sizeof(node));
    node *prevNode;
    if(start == NULL){
        printf("ERROR: memory can't be allocated\n");
        return start;
    }
    temp = start;
    prevNode = temp;
    printf("enter data of first node: ");
    scanf("%d", &elem);
    temp->data = elem;
    temp->ptr  = NULL;
    printf("select mode to enter data\n");
    printf("[1] enter fixed number of data\n");
    printf("[2] enter data till you want\n");
    printf("[3] create no new node\n");
    scanf("%d",&mode);
    switch(mode){
    case 1:
        printf("enter number of data to enter: ");
        scanf("%d", &count);
        i = 1;
        while(i <= count){
            node *newNode = (node *)malloc(sizeof(node));
            if(newNode == NULL){
                printf("ERROR: memory can't be allocated\n");
                return start;
            }
            printf("enter %d th data: ", i);
            scanf("%d", &elem);
            newNode->data = elem;
            prevNode->ptr = newNode;
            prevNode = newNode;
            newNode->ptr = NULL;
            i++;
        }
        break;
    case 2:
        printf("want to add more node? [y/n] ");
        scanf(" %c", &conti);
        while(conti == 'Y' || conti == 'y'){
            node *newNode = (node *)malloc(sizeof(node));
            if(newNode == NULL){
                printf("ERROR: memory can't be allocated\n");
                return start;
            }
            printf("enter data: ");
            scanf("%d", &elem);
            newNode->data = elem;
            prevNode->ptr = newNode;
            prevNode = newNode;
            newNode->ptr = NULL;
            printf("want to add more node? [y/n] ");
            scanf(" %c", &conti);
        }
        break;
        
    default:
        printf("no new node added\n");
        break;
    }
    prevNode->ptr = NULL;
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
//----------------------------------------------------------- 
void insertAfter(node *start, int value, int newValue){
    ///insert new value after
    node *temp;
    node *newNode;
    temp = start;
    if(temp == NULL){
        printf("insertion failed\nlist is empty\n");
        return;
    }
    while(temp->ptr != NULL && temp->data != value){
        temp = temp->ptr;
    }
    if(temp->ptr == NULL && temp->data != value){
        printf("! VALUE ERROR\n");
        printf("insertion operation failed\n");
        return;
    }
    newNode = (node *)malloc(sizeof(node));
    newNode->data = newValue;
    newNode->ptr  = temp->ptr;
    temp->ptr = newNode;
}
//----------------------------------------------------------- 
node *insertBefore(node *start, int value, int newValue){
    node *newStart = start;
    node *temp = start;
    if(start == NULL){
        printf("list is empty\n");
        return newStart;
    }
    else{
        node *prevNode;
        prevNode = temp;
        while(temp->ptr != NULL && temp->data != value){
            prevNode = temp;
            temp = temp->ptr;
        }
        if(temp->ptr == NULL && temp->data != value){
            printf("! VALUE ERROR\n");
            printf("insertion operation failed\n");
            return newStart;
        }
        node *newNode = (node *)malloc(sizeof(node));
        if(newNode == NULL){
            printf("ERROR: memory can't be allocated\n");
            return newStart;
        }
        newNode->data = newValue;
        newNode->ptr  = temp;
        if(temp == start){
            newStart = newNode;
        }
        else{
            prevNode->ptr = newNode;
        }
    }
    return newStart;
}
//----------------------------------------------------------- 
node *insertAtPlace(node *start, int place, int newValue){
    int  i=1;
    node *newStart = start;
    node *temp = start;
    node *prevNode;
    if(temp == NULL){
        printf("list is empty\n");
        return newStart;
    }
    prevNode = temp;
    while(temp->ptr != NULL && i < place){
        prevNode = temp;
        temp = temp->ptr;
        i++;
    }
    if(temp->ptr == NULL && i != place){
        printf("! INDEX ERROR\n");
        printf("insertion operation failed\n");
        return newStart;
    }
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = newValue;
    newNode->ptr  = temp;
    if(temp == start){
        newStart = newNode;
    }
    else{
        prevNode->ptr = newNode;
    }
    return newStart;
}
//----------------------------------------------------------- 
void deleteAfter(node *start, int value){
    node *temp;
    node *toDelete;
    temp = start;
    if(temp == NULL){
        printf("list is empty\n");
        return;
    }
    while(temp->ptr != NULL && temp->data != value){
        temp = temp->ptr;
    }
    if(temp->ptr == NULL && temp->data != value){
        printf("given data not in list\n");
        return;
    }
    if(temp->ptr == NULL && temp->data == value){
        printf("no value to delete after\n");
        return;
    }
    else{
        toDelete = temp->ptr;
        if((temp->ptr)->ptr != NULL){
            temp->ptr = (temp->ptr)->ptr;
        }
        else{
            temp->ptr = NULL;
        }
        free(toDelete);
    }
}
//----------------------------------------------------------- 
node *deleteNode(node *start, int value){
    node *newStart = NULL;
    node *temp = NULL;
    node *prevNode = NULL;
    newStart = start;
    temp = start;
    prevNode = temp;
    while(temp->ptr != NULL && temp->data != value){
        prevNode = temp;
        temp = temp->ptr;
    }
    if(temp->ptr == NULL && temp->data != value){
        printf("can't delete non existing value\n");
        return newStart;
    }
    if(temp == start && temp->ptr != NULL)
        newStart = temp->ptr;
    else if(temp->ptr == NULL)
        newStart = NULL;
    else{
        if(temp->ptr != NULL)
            prevNode->ptr = temp->ptr;
        else
            prevNode->ptr = NULL;
    }
    free(temp);
    return newStart;
}
//----------------------------------------------------------- 
node *deleteNodeAtPos(node *start, int position){
    int i=1;
    node *temp;
    node *newStart;
    node *toDelete;
    node *prevNode;
    temp = start;
    newStart = start;
    if(start == NULL){
        printf("can't delete from empty linklist\n");
        return newStart;
    }
    while(temp->ptr != NULL && i<position){
        prevNode = temp;
        temp = temp->ptr;
        i++;
    }
    if(temp->ptr == NULL && (i != position-1) && position != 1){
        printf("invalid position\n");
        return newStart;
    }
    if(position == 1 && temp->ptr != NULL){
        newStart = temp->ptr;
    }
    else if(position == 1 && temp->ptr == NULL){
        newStart = NULL;
    }
    else{
        if(temp->ptr != NULL)
            prevNode->ptr = temp->ptr;
        else{
            prevNode->ptr = NULL;
        }
    }
    free(toDelete);
    return newStart;
}
//-----------------------------------------------------------    
void linklistOper(node *start){
    printf("double linklist operations to perform\n");
    char conti = 'y';
    int mainChoice;
    int subChoice;
    int position;
    int value, newValue;
    while(conti == 'y' || conti == 'Y'){
        printf("-------------------------------\n");
        printf("[1] create linklist\n");
        printf("[2] insert value in linklist\n");
        printf("[3] delete value in linklist\n");
        printf("[4] traverse\n");
        printf("[5] reverse\n");
        printf("[6] delete odd node\n");
        printf("-------------------------------\n");
        printf("enter operation to perform : ");
        scanf("%d", &mainChoice);
        switch(mainChoice){
        case 1:
            start = createLinklist();
            break;
        case 2:
            printf("-----------------------------\n");
            printf("[1] to insert after a value\n");
            printf("[2] to insert before a value\n");
            printf("[3] to insert at position\n");
            printf("-----------------------------\n");
            printf("which way you want to insert : ");
            scanf("%d", &subChoice);
            switch(subChoice){
            case 1:
                printf("after which value to insert ? : ");
                scanf("%d", &value);
                printf("enter value to insert : ");
                scanf("%d", &newValue);
                insertAfter(start, value, newValue);
                break;
            case 2:
                printf("before which value to insert ? : ");
                scanf("%d", &value);
                printf("enter value to insert : ");
                scanf("%d", &newValue);
                start = insertBefore(start, value, newValue);
                break;
            case 3:
                printf("position to insert : ");
                scanf("%d", &position);
                printf("enter value to insert : ");
                scanf("%d", &newValue);
                start = insertAtPlace(start, position, newValue);
                break;
            default:
                printf("not a valid input\n");
                break;
            }
            break;
        case 3:
            printf("-----------------------------\n");
            printf("[1] to delete after a value\n");
            printf("[2] to delete a value\n");
            printf("[3] to delete a value at position\n");
            printf("-----------------------------\n");
            printf("which way you want to delete : ");
            scanf("%d", &subChoice);
            switch(subChoice){
            case 1:
                printf("after which value to delete ? : ");
                scanf("%d", &value);
                deleteAfter(start, value);
                break;
            case 2:
                printf("enter value to delete: ");
                scanf("%d", &value);
                start = deleteNode(start, value);
                break;
            case 3:
                printf("position to delete : ");
                scanf("%d", &position);
                start = deleteNodeAtPos(start, position);
                break;
            default:
                printf("not a valid input\n");
                break;
            }
            break;
        case 4:
            traverse(start);
            break;
        case 5:
            start = reverse(start);
            break;
        case 6:
            deleteOddNode(&start);
            break;
        default:
            printf("not a valid input\n");
            break;
        }
    printf("want to continue? [y\\n] ");
    scanf(" %c", &conti);
    }
}  
//------------------------------------------------------------
node *reverse(node *start){
    node *newStart = NULL;
    node *previous = NULL;
    node *current  = NULL;
    node *next     = NULL;
    current = start;
    while(current != NULL){
        next = current->ptr;
        current->ptr = previous;
        previous = current;
        current  = next;
    }
    newStart = previous;
    return newStart;
}
//-------------------------------------------------------------
node *createReversed(node *start){
    node *newNode = NULL;
    node *previous = NULL;
    node *temp = NULL;
    temp = start;
    while(temp != NULL){
        newNode = (node *)malloc(sizeof(node));
        newNode->data = temp->data;
        newNode->ptr  = previous;
        previous      = newNode;
        temp = temp->ptr;
    }
    return newNode;
}
//---------------------------------------------------------
void deleteOddNode(node **start){
    node *newStart, *next, *curr;
    newStart = (*start)->ptr;
    if(newStart){
        next = newStart->ptr;
        curr = newStart;
        while(next != NULL && curr != NULL){
            curr->ptr = next->ptr;
            free(next);
            if(curr){
                curr = curr->ptr;
                if(curr)
                    next = curr->ptr;
            }
        }
    }
    free(*start);
    *start = newStart;
}
//---------------------------------------------------------
node *mergeLinklist(node *first, node *second){
    node *merged = NULL;
    node *prev = NULL;
    while(first != NULL && second != NULL){
        if(first->data > second->data){
            if(!merged)
                merged = first;
            while(first != NULL && first->data > second->data){
                prev = first;
                first = first->ptr;
            }
            prev->ptr = second;
        }
        else{
            if(!merged)
                merged = second;
            while(second != NULL && first->data <= second->data){
                prev = second;
                second = second->ptr;
            }
            prev->ptr = first;
        }
    }
    if(!first){
        prev->ptr = second;
        return merged;
    }
    prev->ptr = first;
    return merged;
}
//-----------------------------------------------------------
void splitIntoFour(node **first, node **second, node **three, node **four, node *start){
    int i=0;
    node **arr[4] = {first, second, three, four};
    node *preArr[4] = {NULL, NULL, NULL, NULL};
    node *mainTemp = start;
    node *temp;
    while(mainTemp != NULL){
        for(i=0; i<4 && mainTemp != NULL; i++){
            temp = (node *)malloc(sizeof(node));
            if(*arr[i] == NULL){
               (*arr[i]) = temp;
               //(*arr[i])->data = mainTemp->data;
            }
            temp->data = mainTemp->data;
            if(preArr[i] != NULL)
                preArr[i]->ptr = temp;
            preArr[i] = (*arr[i]);  
            mainTemp = mainTemp->ptr;
        }
    }
}