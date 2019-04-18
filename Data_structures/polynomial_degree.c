#include<stdio.h>

int max(int x, int y);

void poly(int arr[], int degree);

void add_poly(int poly_a[], int, int poly_b[], int, int poly_c[]);

int main(){
    int degree_a, degree_b, degree_c, i;
    printf("Two polynomial adder\n\n");
    char conti = 'y';
    while(conti == 'y'){
        printf("\nEnter the degree of poly A: ");
        scanf("%d", &degree_a);
        int poly_a[degree_a+1];
        poly(poly_a, degree_a);

        printf("\n<---------------------------->\n\n");
        printf("Enter the degree of poly B: ");
        scanf("%d", &degree_b);
        int poly_b[degree_b+1];
        poly(poly_b, degree_b);

        degree_c = max(degree_a, degree_b);
        int poly_c[degree_c+1];
        add_poly(poly_a, degree_a, poly_b, degree_b, poly_c);
        printf("\nadded polynomial is:\n");
        for(i=degree_c; i>=0 ; i--){
            if(poly_c[i]>=0 && i != degree_c){
                printf("+%d(x^%d) ", poly_c[i], i);
            }
            else{
                printf("%d(x^%d) ", poly_c[i], i);
            }
        }
        while(conti == 'y' && conti != 'n'){
            printf("\n\nwant to do more[y/n]? ");
            scanf(" %c", &conti);
            if(conti != 'y' &&  conti !='n'){
                printf("Not a valid input\n");
                conti = 'y';
            }
            else if(conti == 'y' || conti == 'n'){
                break;
            }
        }
    }
    printf("\nThanks for using\n");
}

int max(int x, int y){
    if(x>y){
        return x;
    }
    return y;
}

void poly(int arr[], int degree){
    printf("Enter the terms\n");
    for(int i=degree; i>=0; i--){
        printf("coefficient of x^%d : ", i);
        scanf("%d", &arr[i]);
    }
}

void add_poly(int poly_a[], int deg_a, int poly_b[], int deg_b, int poly_c[]){
    int i, mid;
    int deg_c = max(deg_a, deg_b);
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
