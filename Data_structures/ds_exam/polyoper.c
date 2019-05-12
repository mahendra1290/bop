#include <stdio.h>

typedef struct poly
{
    int coeff;
    int expo;
}polynomial;

int add_poly(polynomial poly1[], polynomial poly2[], int len_1, int len_2, polynomial poly3[]);

int multi_poly(polynomial poly1[], polynomial poly2[], int len_1, int len_2, polynomial poly3[]);

int main(){

}

int add_poly(polynomial poly1[], polynomial poly2[], int len_1, int len_2, polynomial poly3[]){
    int i, k, len_3;
    if (len_1 == 0){
        len_3 = len_2;
        for (i=0; i<len_3; i++){
            poly3[i] = poly2[i];
        }
    }
    else if (len_2 == 0){
        len_3 = len_1;
        for (i=0; i<len_3; i++){
            poly3[i] = poly1[i];
        }
    }
    else {
        int i=0, j=0, k=0;
        while (i < len_1 && j < len_2){
            if (poly1[i].expo == poly2[j].expo){
                poly3[k].expo = poly1[i].expo;
                poly3[k].coeff = poly1[i].coeff + poly2[j].coeff;
                if (poly3[k].coeff != 0){
                    k++;
                }
                i++;
                k++;
            }
            else if (poly1[i].expo < poly2[j].expo){
                i++;
            }
            else {
                j++;
            }
        }
        while (j < len_2){
            poly3[k].expo = poly2[j].expo;
            poly3[k].coeff = poly2[j].coeff;
            k++;
            j++; 
        }
        while (i < len_1){
            poly3[k].expo = poly1[i].expo;
            poly3[k].coeff = poly1[i].coeff;
            k++;
            i++; 
        }
    }
    return k;
}

int multi_poly(polynomial poly1[], polynomial poly2[], int len_1, int len_2, polynomial poly3[]){
    polynomial poly4[30];
    int len_3 = 0;
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    for (i=0; i<len_1; i++){
        k = 0;
        for (j=0; j<len_2; j++){
            poly4[k].coeff = poly1[i].coeff*poly2[j].coeff;
            poly4[k].expo  = poly1[i].expo + poly2[i].expo;
        }
        add_poly(poly4)
    }
}
