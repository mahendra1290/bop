#include <stdio.h>
#include <stdlib.h>

typedef struct binTreeNode *binTreePointer;

typedef struct binTreeNode{
    int data;
    binTreePointer leftChild;
    binTreePointer rightChild;
}binTreeNode;

binTreePointer createBinTree(binTreePointer parent, char child);

void inorderTraversal(binTreePointer root);

void preorderTraversal(binTreePointer root);

int main(){
    binTreePointer root = NULL;
    root = createBinTree(root, 'n');
    inorderTraversal(root);
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
        printf("\nenter left child data of node with data %d :", parent->data);
        scanf("%d", &(root->data));
    }
    else if(child == 'r'){
        printf("\nenter right child data of node with data %d :", parent->data);
        scanf("%d", &(root->data));
    }
    root->leftChild  = NULL;
    root->rightChild = NULL;
    printf("\n<---does left child exist for data %d [y\\n]? ", root->data);
    scanf(" %c", &choice);
    if(choice == 'y'){
        root->leftChild = createBinTree(root, 'l');
    }
    printf("\n<---does right child exist for data %d [y\\n]? ", root->data);
    scanf(" %c", &choice);
    if(choice == 'y'){
        root->rightChild = createBinTree(root, 'r');
    }
    return root;
}

void inorderTraversal(binTreePointer root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->leftChild);
    printf("%d ", root->data);
    inorderTraversal(root->rightChild);
}

void preorderTraversal(binTreePointer root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->leftChild);
    preorderTraversal(root->rightChild);
}