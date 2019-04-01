#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct binTreeNode *binTreePointer;

typedef struct binTreeNode{
    int data;
    binTreePointer leftChild;
    binTreePointer rightChild;
}binTreeNode;

binTreePointer createBinTree(binTreePointer parent, char child);
void inorderTraversal(binTreePointer root);
void preorderTraversal(binTreePointer root);
void postorderTraversal(binTreePointer root);
int findMaxInBinTree(binTreePointer root);
int getSumOfBinTree(binTreePointer root);
int getDepthOfBinTree(binTreePointer root);
int getLeafNodeCount(binTreePointer root);
int getTotalNodeCount(binTreePointer root);
int getNonLeafNodeCount(binTreePointer root);
binTreePointer searchInBinTree(binTreePointer root, int value);
void binTreeOper(binTreePointer root);

int main(){
    binTreePointer root = NULL;
    binTreeOper(root);
}
//--------------------------------------------------------------
binTreePointer createBinTree(binTreePointer parent, char child){
    binTreePointer root = NULL;
    int choice;
    root = (binTreePointer)malloc(sizeof(binTreeNode));
    root->leftChild  = NULL;
    root->rightChild = NULL;
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
    printf("\ndoes left child exist for data %d [1|0]..? ", root->data);
    scanf(" %d", &choice);
    if(choice == 1){
        root->leftChild = createBinTree(root, 'l');
    }
    printf("\ndoes right child exist for data %d [1|0]..? ", root->data);
    scanf(" %d", &choice);
    if(choice == 1){
        root->rightChild = createBinTree(root, 'r');
    }
    return root;
}
//--------------------------------------------
void inorderTraversal(binTreePointer root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->leftChild);
    printf("%d ", root->data);
    inorderTraversal(root->rightChild);
}
//---------------------------------------------
void preorderTraversal(binTreePointer root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->leftChild);
    preorderTraversal(root->rightChild);
}
//---------------------------------------------
void postorderTraversal(binTreePointer root){
    if(root == NULL){
        return;
    }
    postorderTraversal(root->leftChild);
    postorderTraversal(root->rightChild);
    printf("%d ", root->data);
}
//----------------------------------------------
int findMaxInBinTree(binTreePointer root){
    int x, y, z;
    if(root == NULL){
        return INT_MIN;
    }
    x = findMaxInBinTree(root->leftChild);
    y = findMaxInBinTree(root->rightChild);
    z = root->data;
    if(x > y && x > z)
        return x;
    else if(y > x && y >z)
        return y;
    else
        return z;
}
//---------------------------------------------
int getSumOfBinTree(binTreePointer root){
    if(root == NULL){
        return 0;
    }
    return root->data + getSumOfBinTree(root->leftChild) + getSumOfBinTree(root->rightChild);
}
//-------------------------------------------------
int getDepthOfBinTree(binTreePointer root){
    int leftChildDepth;
    int rightChildDepth;
    if(root == NULL){
        return 0;
    }
    leftChildDepth  = getDepthOfBinTree(root->leftChild);
    rightChildDepth = getDepthOfBinTree(root->rightChild);
    if(leftChildDepth > rightChildDepth){
        return (1+leftChildDepth);
    }
    return (1+rightChildDepth);
}
//--------------------------------------------------
int getTotalNodeCount(binTreePointer root){
    if(root == NULL){
        return 0;
    }
    return (1+getTotalNodeCount(root->leftChild)+getTotalNodeCount(root->rightChild));
}
//-------------------------------------------------------------------
int getLeafNodeCount(binTreePointer root){
    if(root == NULL){
        return 0;
    }
    else if(root->leftChild == NULL && root->rightChild == NULL){
        return 1;
    }
    return getLeafNodeCount(root->leftChild)+getLeafNodeCount(root->rightChild);
}
//------------------------------------------------------------------
int getNonLeafNodeCount(binTreePointer root){
    if(root == NULL){
        return 0;
    }
    else if(root->leftChild != NULL || root->rightChild != NULL){
        return 1;
    }
    return getNonLeafNodeCount(root->leftChild)+getNonLeafNodeCount(root->rightChild);
}
//------------------------------------------------------------------
binTreePointer searchInBinTree(binTreePointer root, int value){
    binTreePointer leftSearch  = NULL;
    binTreePointer rightSearch = NULL;
    if(root == NULL){
        return NULL;
    }
    else if(root->data == value){
        return root;
    }
    leftSearch = searchInBinTree(root->leftChild, value);
    if(leftSearch == NULL){
        rightSearch = searchInBinTree(root->rightChild, value);
        return rightSearch;
    }
    return leftSearch;
}
//---------------------------------------------------------
void binTreeOper(binTreePointer root){
    int choice;
    int toSearch;
    int conti;
    do{
        printf("+---------------------------------------+\n");
        printf("| [1]  create binary tree               |\n");
        printf("| [2]  inorder traversal                |\n");
        printf("| [3]  preorder traversal               |\n");
        printf("| [4]  postorder traversal              |\n");
        printf("| [5]  max in binary tree               |\n");
        printf("| [6]  sum of binary tree               |\n");
        printf("| [7]  depth of binary tree             |\n");
        printf("| [8]  leaf node in bin tree            |\n");
        printf("| [9]  total node in binary tree        |\n");
        printf("| [10] get non-leaf node in binary tree |\n");
        printf("| [11] search value in binary tree      |\n");
        printf("+---------------------------------------+\n");
        printf("which operation you want to perform: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                root = createBinTree(root, 'n');
                break;
            case 2:
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                findMaxInBinTree(root);
                break;
            case 6:
                getSumOfBinTree(root);
                break;
            case 7:
                getDepthOfBinTree(root);
                break;
            case 8:
                getLeafNodeCount(root);
                break;
            case 9:
                getTotalNodeCount(root);
                break;
            case 10:
                getNonLeafNodeCount(root);
                break;
            case 11:
                printf("enter value to search: ");
                scanf("%d", &toSearch);
                searchInBinTree(root, toSearch);
                break;
            default:
                break;
        }
        printf("want to do more ? [1|0] : ");
        scanf("%d", &conti);
    }
    while(conti == 1);
}