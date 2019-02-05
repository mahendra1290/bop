#include<stdio.h>

int poly_eval(int poly[], int x, int i, int deg);

int main(){
    int degree, i, j, x;
    printf("enter degree of polynomial: ");
    scanf("%d", &degree);
    int poly[degree+1];
    for(i=0; i<=degree; i++){
        printf("enter the coefficient of x^%d: ", i);
        scanf("%d", &poly[i]);
    }
    printf("enter the value of x: ");
    scanf("%d", &x);
    int sum = poly_eval(poly, x, 0, degree);
    printf("poly evaluation is %d", sum);
}

int poly_eval(int poly[], int x, int i, int deg){
	int sum;
    sum = poly[deg]*x + poly[deg-1];
    deg -= 2;
    while(deg >= 0){
    	sum = poly[deg--] + x*sum;
	}
	return sum;
	
	/*if(i == deg-1){
        return (poly[i] + x*poly[i+1]);
    }
    else{
        return(poly[i] + x*(poly_eval(poly, x, ++i, deg)));
    }*/
}
