//this program find tanspose of a non-square matrix into itself
#include<stdio.h>

#include<stdlib.h>

#define MALLOC(ptr, size) \
    if(!((ptr) = malloc(size))){\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    }

typedef struct matrix{
    int row;
    int col;
    int data;
    struct matrix *next;
}matrix;


matrix *createMatrix(int row, int col){
    int elem;
    matrix *start = NULL;
    matrix *prev = NULL;
    matrix *newTerm = NULL;
    MALLOC(start, sizeof(matrix));
    start->row = row;
    start->col = col;
    start->data = 0;
    start->next = NULL;
    prev = start;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &elem);
            if(elem != 0){
                MALLOC(newTerm, sizeof(matrix));
                newTerm->data = elem;
                newTerm->row = i;
                newTerm->col = j;
                newTerm->next = NULL;
                prev->next = newTerm;
                start->data++;
                prev = newTerm;
            }
        }
    }
    return start;
}

void display(matrix *mat){
    matrix *temp = NULL;
    int row = mat->row;
    int col = mat->col;
    temp = mat->next;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(temp != NULL && (temp->row == i && temp->col == j)){
                printf("%d ", temp->data);
                temp = temp->next;
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    matrix *mat = NULL;
    mat = createMatrix(4, 4);
    display(mat);
    return 0;
}