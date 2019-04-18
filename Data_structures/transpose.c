//this program find tanspose of a non-square matrix into itself
#include <stdio.h>

#include <stdlib.h>

#define MALLOC(ptr, size)                       \
    if (!((ptr) = malloc(size)))                \
    {                                           \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);                     \
    }

typedef struct matrix
{
    int row;
    int col;
    int data;
    struct matrix *next;
} matrix;

matrix *createMatrix(int row, int col);

void display(matrix *mat);

void swap(matrix *x, matrix *y);

void transpose(matrix *mat);

int main()
{
    matrix *mat = NULL;
    mat = createMatrix(4, 4);
    display(mat);
    transpose(mat);
    display(mat);
    return 0;
}

matrix *createMatrix(int row, int col)
{
    printf("enter %d row and %d column\n", row, col);
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
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &elem);
            if (elem != 0)
            {
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

void display(matrix *mat)
{
    matrix *temp = NULL;
    int row = mat->row;
    int col = mat->col;
    temp = mat->next;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (temp != NULL && (temp->row == i && temp->col == j))
            {
                printf("%d ", temp->data);
                temp = temp->next;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void selection(matrix *arr)
{
    matrix *index = NULL;
    matrix *temp_1  = NULL;
    matrix *temp_2  = NULL;
    temp_1 = arr->next;
    while(temp_1)
    {
        index = temp_1;
        temp_2 = temp_1->next;
        while(temp_2)
        {
            if(temp_2->col < index->col){
                index = temp_2;
            }
            temp_2 = temp_2->next;
        }
        swap(temp_1, index);
        temp_1 = temp_1->next;
    }
}

void swap(matrix *x, matrix *y)
{
    matrix temp = *x;
    x->data = y->data;
    x->col  = y->col;
    x->row  = y->row;
    y->data = temp.data;
    y->col  = temp.col;
    y->row  = temp.row;

}
//find transpose of a sparse matrix
void transpose(matrix *mat)
{
    matrix *temp;
    selection(mat);
    temp = mat;
    while(temp){
        int temp_1 = temp->col;
        temp->col = temp->row;
        temp->row = temp_1;
        temp = temp->next;
    }
}

void f_transpose(matrix *mat, matrix *trans){
    int i, j, k, temp;
    trans->col = mat->row;
    trans->row = mat->col;
    trans->val = mat->val;
    int row_terms[mat->col];
    for(i=0; i<mat->col; i++)
    {
        row_terms[i] = 0;
    }
    matrix *temp;
    temp = mat->next;
    while(temp)
    {
        row_terms[temp->col]++;
        temp = temp->next;
    }
    for(i=1; i<=mat[0].val; i++){
        temp = start_pos[mat[i].col]++;
        trans[temp].row = mat[i].col;
        trans[temp].col = mat[i].row;
        trans[temp].val = mat[i].val;
    }
}