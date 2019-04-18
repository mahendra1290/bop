#include<stdio.h>
#include<stdlib.h>


void poly_inp(int poly[], int degree);

int * add_poly(int poly_a[], int poly_b[], int deg_a, int deg_b);

int max(int x, int y);

int main(){
    int degree_a, degree_b, degree_c, i;
    int *poly_c;
    printf("Enter the degree of polynomial: ");
    scanf("%d", &degree_a);
    int poly_a[degree_a+1];
    poly_inp(poly_a, degree_a);

    printf("Enter the degree of polynomial: ");
    scanf("%d", &degree_b);
    int poly_b[degree_b+1];
    poly_inp(poly_b, degree_b);
    degree_c = max(degree_a, degree_b);
    for(i=degree_c; i>=0; i--){
        int a = sizeof(int);
        printf("%d ", *(poly_c+(a*i)));
    }
    poly_c = add_poly(poly_a, poly_b, degree_a, degree_b);

}


void poly_inp(int poly[], int degree){
    int i;
    printf("\n");
    printf("Enter the terms\n");
    for(i=degree; i>=0; i--){
        printf("enter coefficient of degree %d : ", i);
        scanf(" %d", &poly[i]);
    }
}


int * add_poly(int poly_a[], int poly_b[], int deg_a, int deg_b){
    int *arr;
    int i;
    int deg_c, mid;
    if(deg_a > deg_b){
        deg_c = deg_a;
        mid = deg_b;
        arr = (int *)malloc(sizeof(int)*(deg_c+1));
        for(i=mid+1; i<=deg_c; i++){
            *(arr+i) = poly_a[i];
        }
    }
    else{
        deg_c = deg_b;
        mid = deg_a;
        arr = (int *)malloc(sizeof(int)*(deg_c+1));
        for(i=mid+1; i<=deg_c; i++){
            *(arr+i) = poly_b[i];
        }
    }
    for(i=0; i<=mid; i++){
        *(arr+i) = poly_a[i]+poly_b[i];
    }
}

int max(int x, int y){
    if(x > y){
        return x;
    }
    return y;
}
