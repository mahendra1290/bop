#include<stdio.h>

typedef struct Term
{
    int row;
    int col;
    int val;
} matrix;

void read_matrix(matrix arr[]);

void f_transpose(matrix mat[], matrix trans[]);

void disp_matrix(matrix mat[]);

int main(){
    printf("Ready to find fast transpose of sparse matrix!...\n\n");
    matrix mat_1[100], trans_mat[100];
    read_matrix(mat_1);
    f_transpose(mat_1, trans_mat);
    disp_matrix(mat_1);
    disp_matrix(trans_mat);
}

void read_matrix(matrix mat[]){
    //to read matrix
    int term, i, j, k;
    printf("Enter the rows and columns: ");
    scanf("%d %d", &mat[0].row, &mat[0].col);
    mat[0].val = 0;
    printf("enter the terms....\n");
    k = 1;            //to store row col and value
    for(i=0; i<mat[0].row; i++){
        for(j=0; j<mat[0].col; j++){
            scanf("%d", &term);
            if(term){
                mat[k].col = j;
                mat[k].row = i;
                mat[k].val = term;
                mat[0].val++;
                k++;
            }
        }
    }
}

void f_transpose(matrix mat[], matrix trans[]){
    int i, j, k, temp;
    trans[0].col = mat[0].row;
    trans[0].row = mat[0].col;
    trans[0].val = mat[0].val;
    int row_terms[mat[0].col];
    for(i=0; i<mat[0].col; i++){
        row_terms[i] = 0;
    }
    for(i=1; i<=trans[0].val; i++){
        row_terms[mat[i].col]++;
    }
    int start_pos[mat[0].col];
    start_pos[0] = 1;
    for(i=1; i<mat[0].col; i++){
        start_pos[i] = start_pos[i-1]+row_terms[i-1];
    }
    for(i=1; i<=mat[0].val; i++){
        temp = start_pos[mat[i].col]++;
        trans[temp].row = mat[i].col;
        trans[temp].col = mat[i].row;
        trans[temp].val = mat[i].val;
    }
}

void disp_matrix(matrix mat[]){
    int i, j, k = 1;
    printf("\n");
    for(i=0; i<mat[0].row; i++){
        printf("| ");
        for(j=0; j<mat[0].col; j++){
            if(mat[k].row == i && mat[k].col == j){
                printf("%3d ", mat[k].val);
                k++;
            }
            else{
                printf("%3d ", 0);
            }
        }
        printf("|\n");
    }
}
