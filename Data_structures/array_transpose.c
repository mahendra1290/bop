#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int row;
    int col;
    int val;
} elem;

elem *create(int row, int col);
void displayMatrix(elem *matrix);
int max(int x, int y);
void swap(elem *x, elem *y);
void transpose(elem *arr);
void merge(elem *arr, int start, int mid, int end);
void merge_sort(elem *arr, int start, int end);

int main(){
    elem *mat;
    mat = create(1, 3);
    displayMatrix(mat);
    transpose(mat);
    displayMatrix(mat);
}

elem *create(int row, int col){
    int maxSize = row*col;
    int elem;
    elem *matrix = (elem *)malloc(sizeof(elem)*maxSize);
    matrix[0].row = row;
    matrix[0].col = col;
    matrix[0].val = 0;
    int k = 1;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &elem);
            if(elem != 0){
                matrix[k].val = elem;
                matrix[k].row = i;
                matrix[k].col = j;
                matrix[0].val++;
                k++;
            }
        }
    }
    return matrix;
}
//displays matrix 
void displayMatrix(elem *matrix){
    int row = matrix[0].row;
    int col = matrix[0].col;
    int k = 1;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(matrix[k].row == i && matrix[k].col == j){
                printf("%d ", matrix[k++].val);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
} 
//transpose
void transpose(elem *arr){
    int len = arr[0].val;
    merge_sort(arr, 1, len);
    for(int i=0; i<=len; i++){
        int temp = arr[i].row;
        arr[i].row = arr[i].col;
        arr[i].col = temp;
    }
}
void merge_sort(elem *arr, int start, int end){
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

void merge(elem *arr, int start, int mid, int end){
    int len, i = start, j = mid+1, k = 0;
    len = end-start+1;
    elem temp[len];
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


void swap(elem *x, elem *y){
    elem temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int min(int x, int y){
    if(x < y)
        return x;
    return y;
}