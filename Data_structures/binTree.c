#include <stdio.h>
#include <stdlib.h>

typedef struct binTreeNode *binTreePointer;

typedef struct binTreeNode{
    int data;
    binTreePointer leftChild;
    binTreePointer rightChild;
}binTreeNode;

binTreePointer createBinTree(binTreePointer parent, char child);

int main(){
    binTreePointer root = NULL;
    root = createBinTree(root, 'n');
}

binTreePointer createBinTree(binTreePointer parent, char child){
    binTreePointer root = NULL;
    char choice = 'y';
    root = (binTreePointer)malloc(sizeof(binTreeNode));
    if(child == 'n'){
        printf("enter data of root : ");
        scanf("%d", &(root->data));
    }
    else if(child == 'l'){
        printf("enter left child data of node with data %d :", parent->data);
        scanf("%d", &(root->data));
    }
    else if(child == 'r'){
        printf("enter right child data of node with data %d :", parent->data);
        scanf("%d", &(root->data));
    }
    root->leftChild  = NULL;
    root->rightChild = NULL;
    printf("does left child exist for node with data %d [y\\n]? ", root->data);
    scanf(" %c", &choice);
    if(choice == 'y'){
        root->leftChild = createBinTree(root, 'l');
    }
    printf("does right child exist for node with data %d [y\\n]? ", root->data);
    scanf(" %c", &choice);
    if(choice == 'y'){
        root->rightChild = createBinTree(root, 'r');
    }
    return root;
}

