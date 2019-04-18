/*********************************
 * Author     : Mahendra Suthar
 * Date       : 18/04/2019
 * Desciption : Functions to find sum of
 *              lower and upper triangular 
 *              matrix all saddle points
 *********************************/

#include <stdio.h>
#include <stdlib.h>

void createMatrix(int row, int col, int mat[][col]);

void displayMatrix(int row, int col, int mat[][col]);

int getSumOfLowerTriMat(int n, int mat[][n]);

int getSumOfUpperTriMat(int n, int mat[][n]);

int *getSaddlePoints(int n, int matrix[][n], int *length);

int isSaddlePoint(int n, int row, int col, int mat[][n]);

int main (){
    int matrix[3][3];
    createMatrix(3, 3, matrix);
    displayMatrix(3, 3, matrix);
    int *saddle = NULL;
    int len;
    saddle = getSaddlePoints(3, matrix, &len);
    for(int i=0; i<len; i++){
        printf("%d ",saddle[i]);
    }
    return 0;
}

void createMatrix(int row, int col, int mat[][col]){
    printf("enter %d row and %d columns\n", row, col);
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int row, int col, int mat[][col]){
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//to calculate sum of lower triangulat matrix
//parameters : row, matrix in form of 2d array
int getSumOfLowerTriMat(int n, int mat[][n]){
    int total = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            total += mat[i][j];
        }
    }
    return total;
}

int getSumOfUpperTriMat(int n, int mat[][n]){
    int total = 0;
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            total += mat[i][j];
        }
    }
    return total;
}
//returns array of all saddle point in square matrix
int *getSaddlePoints(int n, int matrix[][n], int *length){
    int len = n;
    int *saddlePoints = malloc(n*sizeof(int));
    int colIndex = 0;
    int i, j, k;
    k = 0;
    for (i=0; i<n; i++){
        colIndex = 0;
        for (j=0; j<n; j++){    //find minimum from row
            if (matrix[i][j] < matrix[i][colIndex]){
                colIndex = j;
            }
        }
        for (j=0; j<n; j++){
            if (matrix[i][j] == matrix[i][colIndex]){
                if (isSaddlePoint(n, i, j, matrix)){
                    saddlePoints[k++] = matrix[i][j];
                    if(k == len){
                        saddlePoints = realloc(saddlePoints, sizeof(int)*n*2);
                    }
                    len = 2*n;
                }
            }
        }
    }
    *length = k;
    return saddlePoints;
}
//checks if given element of matrix is a saddle point or not
int isSaddlePoint(int n, int row, int col, int mat[][n]){
    int i;
    for (i=0; i<n; i++){
        //checks it is min and max in row and cols
        if (mat[row][i] < mat[row][col] || mat[i][col] > mat[row][col]){
            return 0;
        }
    }
    return 1;
}
