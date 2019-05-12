/******************************
* Author      : Mahendra Suthar
* Date        : Thu May  9 21:57:34 2019
* Description : This program has function to merge
*               two link list to create a new with 
*               no data in common
* ****************************/
#include <stdio.h>
#include "linklist.h"

node *mergeList(node *first, node *second);
node *linkNode(node *prev, node *new);
node *createNewNode(int data);
void deleteNodeAfter(node *data);
node *copyLinkList(node *list);
node *mergeListWay(node *first, node *second);

int main(){
    node *first = createLinklist();
    node *second = createLinklist(first);
    //raverse(second);
    //traverse(first);
    node *third = NULL;
    node *fourth = NULL;
    fourth = mergeList(first, second);
    third = mergeListWay(first, second);
    //traverse(third);
}
//merges two link list and creates new one with no data common
node *mergeList(node *first, node *second){
    int count = 0;
    node *merged = NULL;
    int flag = 0;
    node *previous = NULL;
    node *newNode = NULL;
    node *temp1 = NULL;
    node *temp2 = NULL;
    node *temp3 = second;
    temp1 = first;
    temp2 = malloc(sizeof(node));
    temp2->ptr = copyLinkList(temp3);
    temp3 = temp2;
    while (temp1 != NULL){
        count++;
        while (temp2->ptr != NULL){
            count++;
            if (temp1->data == (temp2->ptr)->data){
                deleteNodeAfter(temp2);
                flag = 1;
            }
            else {
                temp2 = temp2->ptr;
            }
        }
        if (temp2->ptr == NULL && flag == 0){
            newNode = createNewNode(temp1->data);
            previous = linkNode(previous, newNode);
            if (merged == NULL){
                merged = newNode;
            }
        }
        temp2 = temp3;
        flag = 0;
        temp1 = temp1->ptr;
    }
    previous->ptr = copyLinkList(temp2->ptr);
    printf("first way %d\n", count);
    return merged;
}
//delete a node after a given node
void deleteNodeAfter(node *data){
    if (data != NULL){
        node *toDelete = NULL;
        if (data->ptr != NULL){
            toDelete = data->ptr;
            data->ptr = toDelete->ptr;
            free(toDelete);
        }
    }
}

node *createNewNode(int data){
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->ptr = NULL;
    return newNode;
}

//links prev node to newNode returns pointer of new node
//can be used for further linking
node *linkNode(node *prev, node *new){
    if (prev != NULL){
        prev->ptr = new;
    }
    return new;
}

//returns a copy of given linklist
node *copyLinkList(node *list){
    int count = 0;
    node *temp = list;
    node *newList = NULL;
    node *previous = NULL;
    node *newNode = NULL;
    while (temp != NULL){
        count++;
        newNode = createNewNode(temp->data);
        previous = linkNode(previous, newNode);
        if (newList == NULL){
            newList = newNode;
        }
        temp = temp->ptr;
    }
    printf("copy count %d\n", count);
    return newList;
}

node *mergeListWay(node *first, node *second){
    int count = 0;
    node *temp1 = first;
    node *temp2 = second;
    node *temp3 = second;
    node *newNode = NULL;
    node *prev = NULL;
    node *merged = NULL;
    for (int i=0; i<2; i++){
        while (temp1 != NULL){
            count++;
            while (temp2 != NULL){
                count++;
                if (temp1->data == temp2->data){
                    break;
                }
                temp2 = temp2->ptr;
            }
            if (temp2 == NULL){
                newNode = createNewNode(temp1->data);
                prev = linkNode(prev, newNode);
                if (merged == NULL){
                    merged = newNode;
                }
            }
            temp2 = temp3;
            temp1 = temp1->ptr;
        }
        temp1 = second;
        temp2 = first;
        temp3 = first;
    }
    printf("way %d\n", count);
    return merged;
}