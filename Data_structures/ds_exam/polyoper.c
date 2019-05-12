#include <stdio.h>

typedef struct poly
{
    int coeff;
    int expo;
} polynomial;

int read_poly(polynomial poly[]);

void display_poly(polynomial poly[], int len);

int add_poly(polynomial poly1[], polynomial poly2[], int len_1, int len_2, polynomial poly3[]);

int multi_poly(polynomial poly1[], polynomial poly2[], int len_1, int len_2, polynomial poly3[]);

int main()
{
    polynomial poly1[40], poly2[40], poly3[40];
    int len1, len2, len3;
    len1 = read_poly(poly1);
    printf("second\n");
    len2 = read_poly(poly2);
    display_poly(poly1, len1);
    display_poly(poly2, len2);
    printf("added\n");
    len3 = multi_poly(poly1, poly2, len1, len2, poly3);
    display_poly(poly3, len3);
}



int read_poly(polynomial poly[])
{
    int len = 0;
    int i = 0;
    while (1){
        printf("enter coeff :");
        scanf("%d", &poly[i].coeff);
        printf("enter expo  :");
        scanf("%d", &poly[i].expo);
        if (poly[i].expo == 0){
            len++;
            break;
        }
        else if (poly[i].expo == -1){
            break;
        }
        len++;
        i++;
    }
    return len;
}

void display_poly(polynomial poly[], int len){
    int i = 0;
    for (i=0; i<len; i++){
        printf("+ %d x^%d ", poly[i].coeff, poly[i].expo);
    }
    printf("\n");
}

int add_poly(polynomial poly1[], polynomial poly2[], int len_1, int len_2, polynomial poly3[])
{
    int i = 0, j = 0, k = 0, len_3;
    if (len_1 == 0)
    {
        len_3 = len_2;
        for (i = 0; i < len_3; i++)
        {
            poly3[i] = poly2[i];
        }
        return len_3;
    }
    else if (len_2 == 0)
    {
        len_3 = len_1;
        for (i = 0; i < len_3; i++)
        {
            poly3[i] = poly1[i];
        }
        return len_3;
    }
    else
    {
        while (i < len_1 && j < len_2)
        {
            if (poly1[i].expo == poly2[j].expo)
            {
                poly3[k].expo = poly1[i].expo;
                poly3[k].coeff = poly1[i].coeff + poly2[j].coeff;
                if (poly3[k].coeff != 0)
                {
                    k++;
                }
                i++;
                j++;
            }
            else if (poly1[i].expo > poly2[j].expo)
            {
                poly3[k].expo = poly1[i].expo;
                poly3[k].coeff = poly1[i].coeff;
                k++;
                i++;
            }
            else
            {
                poly3[k].expo = poly2[j].expo;
                poly3[k].coeff = poly2[j].coeff;
                k++;
                j++;
            }
        }
        while (j < len_2)
        {
            poly3[k].expo = poly2[j].expo;
            poly3[k].coeff = poly2[j].coeff;
            k++;
            j++;
        }
        while (i < len_1)
        {
            poly3[k].expo = poly1[i].expo;
            poly3[k].coeff = poly1[i].coeff;
            k++;
            i++;
        }
    }
    return k;
}

int multi_poly(polynomial poly1[], polynomial poly2[], int len_1, int len_2, polynomial poly3[])
{
    polynomial poly4[50];
    polynomial poly5[50];
    int len_3 = 0;
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    for (i = 0; i < len_1; i++)
    {
        k = 0;
        for (j = 0; j < len_2; j++)
        {
            poly4[k].coeff = poly1[i].coeff * poly2[j].coeff;
            poly4[k].expo = poly1[i].expo + poly2[j].expo;
            k++;
        }
        //printf("poly 4\n");
        //display_poly(poly4, k);
        //printf("k %d\n", k);

        /*
        poly4 is temporary
        we want poly3 = poly3 + poly4
        so we used poly5
        poly3 = poly4 + poly5
        poly5 = poly3
        */
        len_3 = add_poly(poly4, poly5, k, len_3, poly3);
        for (int i=0; i<len_3; i++){
            poly5[i].coeff = poly3[i].coeff;
            poly5[i].expo  = poly3[i].expo;
        }
        // printf("len 3 %d\n", len_3);
        // printf("poly3\n");
        // display_poly(poly3, len_3);
    }
    return len_3;
}
