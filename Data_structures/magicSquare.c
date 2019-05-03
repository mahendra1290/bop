#include <stdio.h>

void createMagicSquare(int size, int mat[size][size]);

int main(){
    int mat[9][9];
    int size = 9;
    createMagicSquare(size, mat);
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

}

void createMagicSquare(int size, int mat[size][size]){
    int i, j;
    int count = 1;
    for (i = 0; i<size; i++){
        for (j=0; j<size; j++){
            mat[i][j] = 0;
        }
    }
    i = 0;
    j = size/2;
    while (count < size*size+1){
        if (mat[i][j] == 0){
            mat[i][j] = count++;
            i--;
            j--;
        }
        else {
            i += 2;
            j ++;
        }
        if (i < 0){
            i = size-1;
        }
        if (j < 0){
            j = size-1;
        }
        i = i%size;
        j = j%size;
    }
}