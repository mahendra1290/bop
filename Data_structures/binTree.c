#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MALLOC(ptr, size) \
    if(!((ptr) = malloc(size))){\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    }

#define NODE_SIZE (sizeof(treeNode))

typedef struct treeNode *treePointer;

typedef struct treeNode{
    int data;
    treePointer left;
    treePointer right;
    treePointer parent;
}treeNode;

treePointer createBinTree(treePointer parent, char child);
void inorderTraversal(treePointer root);
void preorderTraversal(treePointer root);
void postorderTraversal(treePointer root);
int findMaxInBinTree(treePointer root);
int getSumOfBinTree(treePointer root);
int getDepthOfBinTree(treePointer root);
int getLeafNodeCount(treePointer root);
int getTotalNodeCount(treePointer root);
int getNonLeafNodeCount(treePointer root);
treePointer searchInBinTree(treePointer root, int value);
void binTreeOper(treePointer root);
treePointer insertion(treePointer root, int value);
treePointer createBinSearchTree(treePointer root, int val);
treePointer searchInBst(treePointer root, int val);
void deleteNode(treePointer node);
treePointer getSuccessor(treePointer node);
treePointer getPreccessor(treePointer node);

int main(){
    treePointer root = NULL;
    root = createBinSearchTree(root, 10);
    inorderTraversal(root);
    treePointer temp;
    temp = searchInBinTree(root, 5);
    deleteNode(temp);
    inorderTraversal(root);
}
//create binary search tree
treePointer createBinSearchTree(treePointer root, int noOfItems){
    if(noOfItems == 0){
        return root;
    }
    int value;
    scanf("%d", &value);
    if(root == NULL){
        root = insertion(root, value);
    }
    else{
        insertion(root, value);
    }
    return createBinSearchTree(root, noOfItems-1);
}
//--------------------------------------------------------------
treePointer createBinTree(treePointer parent, char child){
    treePointer root = NULL;
    int choice;
    root = (treePointer)malloc(sizeof(treeNode));
    root->left  = NULL;
    root->right = NULL;
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
        root->left = createBinTree(root, 'l');
    }
    printf("\ndoes right child exist for data %d [1|0]..? ", root->data);
    scanf(" %d", &choice);
    if(choice == 1){
        root->right = createBinTree(root, 'r');
    }
    return root;
}
//--------------------------------------------
void inorderTraversal(treePointer root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
//---------------------------------------------
void preorderTraversal(treePointer root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
//---------------------------------------------
void postorderTraversal(treePointer root){
    if(root == NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}
//----------------------------------------------
int findMaxInBinTree(treePointer root){
    int x, y, z;
    if(root == NULL){
        return INT_MIN;
    }
    x = findMaxInBinTree(root->left);
    y = findMaxInBinTree(root->right);
    z = root->data;
    if(x > y && x > z)
        return x;
    else if(y > x && y >z)
        return y;
    else
        return z;
}
//---------------------------------------------
int getSumOfBinTree(treePointer root){
    if(root == NULL){
        return 0;
    }
    return root->data + getSumOfBinTree(root->left) + getSumOfBinTree(root->right);
}
//-------------------------------------------------
int getDepthOfBinTree(treePointer root){
    int leftChildDepth;
    int rightChildDepth;
    if(root == NULL){
        return 0;
    }
    leftChildDepth  = getDepthOfBinTree(root->left);
    rightChildDepth = getDepthOfBinTree(root->right);
    if(leftChildDepth > rightChildDepth){
        return (1+leftChildDepth);
    }
    return (1+rightChildDepth);
}
//--------------------------------------------------
int getTotalNodeCount(treePointer root){
    if(root == NULL){
        return 0;
    }
    return (1+getTotalNodeCount(root->left)+getTotalNodeCount(root->right));
}
//-------------------------------------------------------------------
int getLeafNodeCount(treePointer root){
    if(root == NULL){
        return 0;
    }
    else if(root->left == NULL && root->right == NULL){
        return 1;
    }
    return getLeafNodeCount(root->left)+getLeafNodeCount(root->right);
}
//------------------------------------------------------------------
int getNonLeafNodeCount(treePointer root){
    if(root == NULL){
        return 0;
    }
    else if(root->left != NULL || root->right != NULL){
        return 1;
    }
    return getNonLeafNodeCount(root->left)+getNonLeafNodeCount(root->right);
}
//------------------------------------------------------------------
treePointer searchInBinTree(treePointer root, int value){
    treePointer leftSearch  = NULL;
    treePointer rightSearch = NULL;
    if(root == NULL){
        return NULL;
    }
    else if(root->data == value){
        return root;
    }
    leftSearch = searchInBinTree(root->left, value);
    if(leftSearch == NULL){
        rightSearch = searchInBinTree(root->right, value);
        return rightSearch;
    }
    return leftSearch;
}
//---------------------------------------------------------
void binTreeOper(treePointer root){
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

treePointer insertion(treePointer root, int value){
    if(root==NULL){
        MALLOC(root, NODE_SIZE);
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        return root;
    }
    else{
        if(value > root->data){
            if(root->right != NULL){
                insertion(root->right, value);
            }
            else{
                treePointer newNode = NULL;
                MALLOC(newNode, NODE_SIZE);
                newNode->data = value;
                newNode->right = NULL;
                newNode->left = NULL;
                newNode->parent = root;
                root->right = newNode;
            }
        }
        else{
            if(root->left != NULL){
                insertion(root->left, value);
            }
            else{
                treePointer newNode = NULL;
                MALLOC(newNode, NODE_SIZE);
                newNode->data = value;
                newNode->right = NULL;
                newNode->left = NULL;
                newNode->parent = root;
                root->left = newNode;
            }
        }
    }
    return root;
}
//search function for bst
treePointer searchInBst(treePointer root, int val){
    if(root == NULL || root->data == val)
        return root;
    if(val > root->data)
        return searchInBinTree(root->right, val);
    return searchInBinTree(root->left, val);
}
//get successor of a node
treePointer getSuccessor(treePointer node){
    treePointer y = NULL;
    treePointer parent = NULL;
    if(node == NULL)
        return node;
    y = node->right;
    if(y == NULL){
        parent = node->parent;
        while(parent != NULL && node != NULL){
            if(parent->left == node){
                break;
            }
            node = node->parent;
        }
        return parent;
    }
    while(y->left != NULL){
        y = y->left;
    }
    return y;
}
//get preccessor of node
treePointer getPreccessor(treePointer node){
    treePointer y = NULL;
    treePointer parent = NULL;
    if(node == NULL)
        return node;
    y = node->left;
    if(y == NULL){
        parent = node->parent;
        while(parent != NULL && node != NULL){
            if(parent->right == node){
                break;
            }
            node = node->parent;
        }
        return parent;
    }
    while(y->right != NULL){
        y = y->right;
    }
    return y;
}

void deleteNode(treePointer node){
    if(node){
        if(node->left == NULL && node->right == NULL){
            treePointer parent = node->parent;
            if(parent){
                if(parent->left == node)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            free(node);
        }
        else if(node->left == NULL || node->right == NULL){
            treePointer parent = node->parent;
            if(parent && node->left){
                if(node == parent->left){
                    parent->left = node->left;
                }
                else{
                    parent->right = node->left;
                }
                (node->left)->parent = parent;
            }
            else if(parent && node->right){
                if(node == parent->left){
                    parent->left = node->right;
                }
                else{
                    parent->right = node->right;
                }
                (node->right)->parent = parent;
            }
            free(node);
        }
        else{
            treePointer successor = getSuccessor(node);
            node->data = successor->data;
            deleteNode(successor);
        }
    }
}