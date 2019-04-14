#include <stdio.h>
#include <stdlib.h>

typedef struct Term{
    int row;
    int col;
    int val;
} matrix;

matrix *create(int row, int col);
void displayMatrix(matrix *mat);
void transpose(matrix *arr);
void merge(matrix *arr, int start, int mid, int end);
void merge_sort(matrix *arr, int start, int end);
matrix *multiply(matrix *mat_1, matrix *mat_2);

int main(){
    matrix *mat_1 = NULL; 
    matrix *mat_2 = NULL;
    matrix *mat_3 = NULL;
    mat_1 = create(2, 3);
    mat_2 = create(3, 2);
    mat_3 = multiply(mat_1, mat_2);
    displayMatrix(mat_3);
}

matrix *create(int row, int col){
    printf("row %d and column %d\n", row, col);
    int maxSize = row*col;
    int value;
    matrix *mat = NULL;
    mat = malloc(sizeof(matrix)*(maxSize+1));
    mat[0].row = row;
    mat[0].col = col;
    mat[0].val = 0;
    int k = 1;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &value);
            if(value != 0){
                mat[k].val = value;
                mat[k].row = i;
                mat[k].col = j;
                mat[0].val++;
                k++;
            }
        }
    }
    return mat;
}
//displays mat 
void displayMatrix(matrix *mat){
    int row = mat[0].row;
    int col = mat[0].col;
    int k = 1;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(mat[k].row == i && mat[k].col == j){
                printf("%d ", mat[k++].val);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
} 
//transpose
void transpose(matrix *arr){
    int len = arr[0].val;
    merge_sort(arr, 1, len);
    for(int i=0; i<=len; i++){
        int temp = arr[i].row;
        arr[i].row = arr[i].col;
        arr[i].col = temp;
    }
}
void merge_sort(matrix *arr, int start, int end){
    //reverse = 0 for normal reverse = 1 for sort in reverse....
    //end is last index and start is first
    int mid = (start+end)/2;
    if(start>=end){
        return;
    }
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

void merge(matrix *arr, int start, int mid, int end){
    int len, i = start, j = mid+1, k = 0;
    len = end-start+1;
    matrix temp[len];
    while(i <= mid && j <= end){
        if(arr[j].col < arr[i].col){
            temp[k] = arr[j++];
        }
        else{
            temp[k] = arr[i++];
        }
        k++;
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= end){
        temp[k++] = arr[j++];
    }
    for(i=start; i<=end; i++){
        arr[i] = temp[i-start];
    }
}
//multiply sparse mat
matrix *multiply(matrix *mat_1, matrix *mat_2){
    matrix *mat_3 = NULL;
    if(mat_1[0].col == mat_2[0].row){
        transpose(mat_2);
    }
    int maxSize = mat_1[0].row * mat_2[0].row;
    mat_3 = malloc((sizeof(matrix)*(maxSize+1)));
    mat_3[0].row = mat_1[0].row;
    mat_3[0].col = mat_2[0].row;
    mat_3[0].val = 0;
    int lastIndex = 0;
    for(int i=mat_1[0].val; i>1; i++){
        if(mat_1[i].row != mat_1[i-1].row){
            lastIndex = i;
            break; 
        }
    }
    int index = 0;
    int colIndex = 0;
    int i = 1;
    int j = 1;
    int k = 1;
    int count = 0;
    int temp = 0;
    while(i <= mat_1[0].val){
        index = i;
        j = 1;
        while(j <= mat_2[0].val){
            temp = 0;
            colIndex = j;
            do{
                if(mat_1[i].col == mat_2[j].col){
                    temp += mat_1[i].val * mat_2[j].val;
                    i++;
                    j++;
                }
                else if(mat_2[j].col > mat_1[i].col){
                    i++;
                }
                else{
                    j++;
                }
            }while((i <= mat_1[0].val) && ((mat_2[colIndex].row == mat_2[j].row)
                    && (mat_1[index].row == mat_1[i].row)));
            if(temp){
                mat_3[k].row = mat_1[index].row;
                mat_3[k].col = mat_2[colIndex].row;
                mat_3[k].val = temp;
                mat_3[0].val++;
                k++;
            }
            if(index != lastIndex){
                i = index;
            }
        }
        do{
            i++;
        }
        while(mat_1[index].row == mat_1[i].row && i < mat_1[0].val);
    }
    return mat_3;
}
