/******************************
* Author      : Mahendra Suthar
* Date        : Sat May 11 15:05:40 2019
* Description : All function related to matrix operatioin
* Functions   : 1. readMatrix
*               2. displayMatrix
*               3. getFastTranspose
*               4. transpose
* ****************************/

#include <stdio.h>

typedef struct{
    int row;
    int col;
    int val;
} matrix;

void readMatrix(matrix mat[], int row, int col);
void displayMatrix(matrix mat[]);
void transpose(matrix mat[]);
void getFastTranspose(matrix mat[], matrix matTrans[]);

int main(){
    matrix mat[10];
    readMatrix(mat, 3, 3);
    displayMatrix(mat);
    matrix mat2[10];
    getFastTranspose(mat, mat2);
    displayMatrix(mat2);
}
//function to read matrix of given row, col
void readMatrix(matrix mat[], int row, int col){
    mat[0].row = row;
    mat[0].col = col;
    int k=1;
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            scanf("%d", &mat[k].val);
            if (mat[k].val != 0){
                mat[k].row = i;
                mat[k].col = j;
                k++;
            }
        } 
    }
    mat[0].val = k-1;
}
//function to display matrix 
void displayMatrix(matrix mat[]){
    int row = mat[0].row;
    int col = mat[0].col;
    int k=1;
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            if (mat[k].row == i && mat[k].col == j){
                printf("%d ", mat[k++].val);
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
//returns transpose of given matrix
//method used is fast transpose
void getFastTranspose(matrix mat[], matrix mat2[]){
    mat2[0].row = mat[0].col;
    mat2[0].col = mat[0].row;
    mat2[0].val = mat[0].val;
    int rowTerm[mat[0].col+1];
    int i, index;
    int k =1;
    for (i=0; i<=mat[0].col; i++){
        rowTerm[i] = 0;
    }
    for (i=1; i<=mat[0].val; i++){
        rowTerm[mat[i].col+1]++;
    }
    rowTerm[0] = 1;
    for (i=1; i<mat[0].col; i++){
        rowTerm[i] += rowTerm[i-1];
    }
    for (i=1; i<=mat[0].val; i++){
        index = rowTerm[mat[i].col]++;
        mat2[k].row = mat[index].col;
        mat2[k].col = mat[index].row;
        mat2[k].val = mat[index].val;
        k++;
    }
}