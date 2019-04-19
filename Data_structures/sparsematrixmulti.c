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
//sparse matix multiplication without helper array
matrix *multiply(matrix *mat_1, matrix *mat_2)
{
    matrix *mat_3 = NULL;
    if (mat_1[0].col == mat_2[0].row)
    {
        transpose(mat_2);
    }
    else
    {
        return mat_3;
    }
    int maxSize = mat_1[0].row * mat_2[0].row;
    mat_3 = malloc((sizeof(matrix) * (maxSize + 1)));
    mat_3[0].row = mat_1[0].row;
    mat_3[0].col = mat_2[0].row;
    mat_3[0].val = 0;
    int currRow = 1;
    int currCol = 1;
    int i = 1;
    int j = 1;
    int k = 1;
    int temp = 0;
    while (currRow < mat_1[0].val)
    {
        while (currCol < mat_2[0].val)
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
                if (mat_1[i].row != mat_1[currRow].row || mat_2[j].row != mat_2[currCol].row ||
                    (i > mat_1[0].val && j > mat_2[0].val))
                {
                    if (temp)
                    {
                        mat_3[k].val = temp;
                        mat_3[k].row = mat_1[currRow].row;
                        mat_3[k].col = mat_2[currCol].row;
                        mat_3[0].val++;
                        temp = 0;
                        k++;
                    }
                    break;
                }
            }
            if (mat_1[i].row != mat_1[currRow].row)
            {
                while (j < mat_2[0].val &&
                       (mat_2[j].row == mat_2[currCol].row))
                {
                    j++;
                }
                if (j != mat_2[0].val)
                {
                    currCol = j;
                    i = currRow;
                }
                else
                {
                    j = 1;
                    break;
                }
            }
            else if (mat_2[j].row != mat_2[currCol].row)
            {
                currCol = j;
                i = currRow;
            }
            else
            {
                break;
            }
        }
        while (i < mat_1[0].val &&
               (mat_1[i].row == mat_1[currRow].row))
        {
            i++;
        }
        if (i != mat_1[0].val)
        {
            currRow = i;
            i = currRow;
            currCol = 1;
            j = currCol;
        }
        else
        {
            break;
        }
    }
    transpose(mat_2);
    return mat_3;
}