#include<stdio.h>

int max(int x, int y);

void poly(int poly[], int degree);

void add_poly(int poly_a[], int deg_a, int poly_b[], int deg_b, int poly_c[]);

void display(int poly[], int deg);

int main(){
    int deg_a, deg_b, deg_c, i;
    char conti = 'y';
    printf("Two polynomial adder\n\n");
    while(conti == 'y'){
        printf("Enter the degree of poly_A: ");
        scanf("%d", &deg_a);
        int poly_a[deg_a+1];
        poly(poly_a, deg_a);

        printf("Enter the degree of poly_B: ");
        scanf("%d", &deg_b);
        int poly_b[deg_b+1];
        poly(poly_b, deg_b);

        deg_c = max(deg_a, deg_b);
        int poly_c[deg_c+1];

        add_poly(poly_a, deg_a, poly_b, deg_b, poly_c);
        display(poly_c, deg_c);

    }
}

int max(int x, int y){
    if(x > y){
        return x;
    }
    return y;
}

void poly(int poly[], int degree){
    int i;
    printf("Enter the terms...\n");
    for(i=degree; i>=0; i--){
        printf("enter the coefficient of x^%d: ",i);
        scanf("%d",&poly[i]);
    }
}

void add_poly(int poly_a[], int deg_a, int poly_b[], int deg_b, int poly_c[]){
    int mid, i, deg_c;
    deg_c = max(deg_a, deg_b);
    if(deg_a == deg_c){
        for(i=deg_b+1; i<=deg_c; i++){
            poly_c[i] = poly_a[i];
        }
        mid = deg_b;
    }
    else{
        for(i=deg_a+1; i<=deg_c; i++){
            poly_c[i] = poly_b[i];
        }
        mid = deg_a;
    }
    for(i=0; i<=mid; i++){
        poly_c[i] = poly_a[i]+poly_b[i];
    }
}

void display(int poly[], int deg){
    int i;
    printf("polynomial is...\n\n");
    for(i=deg; i>=0; i--){
        if(poly[i]){
            if(poly[i] > 0 && i != deg){
                printf("+%d(x^%d) ", poly[i], i);
            }
            else{
                printf("%d(x^%d) ", poly[i], i);
            }
        }
    }
}
