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
    if(child == 'n' || child == 'N'){
        printf("enter data of root : ");
        scanf("%d", &(root->data));
    }
    else if(child == 'l' || child == 'L'){
        printf("enter left branch data of %d :", parent->data);
        scanf("%d", &(root->data));
    }
    else if(child == 'r' || child == 'R'){
        printf("enter right branch data of %d :", parent->data);
        scanf("%d", &(root->data));
    }
    root->leftChild  = NULL;
    root->rightChild = NULL;
    printf("left branch present ? ");
    fflush(stdin);
    scanf(" %c", &choice);
    if(choice == 'y'){
        root->leftChild = createBinTree(root, 'l');
    }
    fflush(stdin);
    printf("right branch present ? ");
    scanf(" %c", &choice);
    if(choice == 'y'){
        root->rightChild = createBinTree(root, 'r');
    }
    fflush(stdin);
    return root;
}

