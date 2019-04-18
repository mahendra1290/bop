/********************************
 * Author      : Mahendra Suthar
 * Date        : 18/04/2019
 * Description : Sparse matrix multiplication 
 *               function by using transpose
 * ******************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *back;
} node;

typedef struct Term
{
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
void insert(node **start, int val);
void display(node *start);

int main()
{
    matrix *mat_1 = NULL;
    matrix *mat_2 = NULL;
    matrix *mat_3 = NULL;
    mat_1 = create(3, 4);
    mat_2 = create(4, 5);
    mat_3 = multiply(mat_1, mat_2);
    displayMatrix(mat_3);
}

matrix *create(int row, int col)
{
    printf("row %d and column %d\n", row, col);
    int maxSize = row * col;
    int value;
    matrix *mat = NULL;
    mat = malloc(sizeof(matrix) * (maxSize + 1));
    mat[0].row = row;
    mat[0].col = col;
    mat[0].val = 0;
    int k = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &value);
            if (value != 0)
            {
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
void displayMatrix(matrix *mat)
{
    int row = mat[0].row;
    int col = mat[0].col;
    int k = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[k].row == i && mat[k].col == j)
            {
                printf("%d ", mat[k++].val);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
//transpose
void transpose(matrix *arr)
{
    int len = arr[0].val;
    merge_sort(arr, 1, len);
    for (int i = 0; i <= len; i++)
    {
        int temp = arr[i].row;
        arr[i].row = arr[i].col;
        arr[i].col = temp;
    }
}
//merge_sort to find transpose
void merge_sort(matrix *arr, int start, int end)
{
    int mid = (start + end) / 2;
    if (start >= end)
    {
        return;
    }
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void merge(matrix *arr, int start, int mid, int end)
{
    int len, i = start, j = mid + 1, k = 0;
    len = end - start + 1;
    matrix temp[len];
    while (i <= mid && j <= end)
    {
        if (arr[j].col < arr[i].col)
        {
            temp[k] = arr[j++];
        }
        else
        {
            temp[k] = arr[i++];
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    for (i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}
//multiply sparse matrix using transpose
/* matrix *multiply(matrix *mat_1, matrix *mat_2)
{
    matrix *mat_3 = NULL;
    if (mat_1[0].col == mat_2[0].row)
    {
        transpose(mat_2);
    }
    displayMatrix(mat_2);
    int maxSize = mat_1[0].row * mat_2[0].row;
    mat_3 = malloc((sizeof(matrix) * (maxSize + 1)));
    mat_3[0].row = mat_1[0].row;
    mat_3[0].col = mat_2[0].row;
    mat_3[0].val = 0;
    node *first = NULL;
    node *second = NULL;
    insert(&first, 1);
    insert(&second, 1);
    for (int i = 1; i <= mat_1[0].val; i++)
    {
        if (mat_1[i].row != mat_1[(first->back)->data].row)
        {
            insert(&first, i);
        }
    }
    insert(&first, mat_1[0].val+1);
    for (int i = 1; i <= mat_2[0].val; i++)
    {
        if (mat_2[i].row != mat_2[(second->back)->data].row)
        {
            insert(&second, i);
        }
    }
    insert(&second, mat_2[0].val+1);
    printf("first :\n");
    display(first);
    printf("second :\n");
    display(second);
    node *temp_1 = first;
    node *temp_2 = second;
    int k = 1;
    int i = 0;
    int j = 0;
    int temp = 0;
    do{
        i = temp_1->data;
        temp_2 = second;
        j = temp_2->data;
        while(i < (temp_1->next)->data){
            temp = 0;
            j = temp_2->data;
            while(j < (temp_2->next)->data && i < (temp_1->next)->data){
                if(mat_1[i].col == mat_2[j].col){
                    temp += mat_1[i].val * mat_2[j].val;
                    i++;
                    j++;
                }
                else if(mat_1[i].col < mat_2[j].col){
                    i++;
                }
                else{
                    j++;
                }
            }
            if(temp){
                mat_3[k].val = temp;
                mat_3[k].row = mat_1[temp_1->data].row;
                mat_3[k].col = mat_2[temp_2->data].row;
                k++;
            }
            i = temp_1->data;
            temp_2 = temp_2->next;
            if(temp_2->data >= mat_2[0].val){
                break;
            }
        }
        temp_1 = temp_1->next;
    }while(temp_1->data < mat_1[0].val+1);

    return mat_3;
} */
//insert element into linklist
void insert(node **start, int val)
{
    node *newNode = NULL;
    newNode = malloc(sizeof(node));
    newNode->data = val;
    if (!(*start))
    {
        *start = newNode;
        (*start)->back = *start;
        (*start)->next = *start;
    }
    else
    {
        node *prev = NULL;
        prev = (*start)->back;
        prev->next = newNode;
        newNode->back = prev;
        newNode->next = *start;
        (*start)->back = newNode;
    }
}

void display(node *start)
{
    if (start)
    {
        node *temp = start;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != start);
        printf("\n");
    }
}
//sparse matix multiplication without helper array
matrix *multiply(matrix *mat_1, matrix *mat_2)
{
    matrix *mat_3 = NULL;
    if (mat_1[0].col == mat_2[0].row)
    {
        transpose(mat_2);
    }
    int maxSize = mat_1[0].row * mat_2[0].row;
    mat_3 = malloc((sizeof(matrix) * (maxSize + 1)));
    mat_3[0].row = mat_1[0].row;
    mat_3[0].col = mat_2[0].row;
    mat_3[0].val = 0;
    int rowIndex = 1;
    int colIndex = 1;
    int i = 1;
    int j = 1;
    int k = 1;
    int temp = 0;
    while (rowIndex < mat_1[0].val)
    {
        while (colIndex < mat_2[0].val)
        {
            while (1)
            {
                if (mat_1[i].col == mat_2[j].col)
                {
                    temp += mat_1[i].val * mat_2[j].val;
                    i++;
                    j++;
                }
                else if (mat_1[i].col < mat_2[j].col)
                {
                    i++;
                }
                else
                {
                    j++;
                }
                if (mat_1[i].row != mat_1[rowIndex].row || mat_2[j].row != mat_2[colIndex].row ||
                    (i > mat_1[0].val && j > mat_2[0].val))
                {
                    if (temp)
                    {
                        mat_3[k].val = temp;
                        mat_3[k].row = mat_1[rowIndex].row;
                        mat_3[k].col = mat_2[colIndex].row;
                        mat_3[0].val++;
                        temp = 0;
                        k++;
                    }
                    break;
                }
            }
            if (mat_1[i].row != mat_1[rowIndex].row)
            {
                while (j < mat_2[0].val &&
                       (mat_2[j].row == mat_2[colIndex].row))
                {
                    j++;
                }
                if (j != mat_2[0].val)
                {
                    colIndex = j;
                    i = rowIndex;
                }
                else
                {
                    j = 1;
                    break;
                }
            }
            else if (mat_2[j].row != mat_2[colIndex].row)
            {
                colIndex = j;
                i = rowIndex;
            }
            else
            {
                break;
            }
        }
        while (i < mat_1[0].val &&
               (mat_1[i].row == mat_1[rowIndex].row))
        {
            i++;
        }
        if (i != mat_1[0].val)
        {
            rowIndex = i;
            i = rowIndex;
            colIndex = 1;
            j = colIndex;
        }
        else
        {
            break;
        }
    }
    transpose(mat_2);
    return mat_3;
}