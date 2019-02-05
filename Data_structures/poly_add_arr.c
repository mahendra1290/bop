#include<stdio.h>

int polyinp(int poly[][2]);

int add_poly(int poly_a[][2], int len_a, int poly_b[][2], int len_b, int poly_c[][2]);

void display(int poly[][2], int len);

int main(){
	printf("Polynomial adder\n");
	int len_a, len_b, len_c;
	int poly_a[50][2], poly_b[50][2], poly_c[50][2];
	printf("enter the terms of poly_A...\n");
	len_a = polyinp(poly_a);
	printf("enter the terms of poly_B...\n");
	len_b = polyinp(poly_b);
	len_c = add_poly(poly_a, len_a, poly_b, len_b, poly_c);
	display(poly_c, len_c);
	
}

int polyinp(int poly[][2]){
	int i, exp=1, val;
    printf("enter the terms from high degree to low...\n");
    printf("enter -1 -1 to exit\n");
    i = 0;
    while(exp){
    	printf("enter the degree and coeficient: ");
    	scanf("%d %d", &exp, &val);
    	if(exp == -1){
    		break;
		}
		poly[i][0] = exp;
		poly[i][1] = val;
		i++;
	}
	return i;
}

int add_poly(int poly_a[][2], int len_a, int poly_b[][2], int len_b, int poly_c[][2]){
	int i =0, j=0, k=0;
	while(i<len_a && j<len_b){
		if(poly_a[i][0] > poly_b[j][0]){
			poly_c[k][0] = poly_a[i][0];
			poly_c[k][1] = poly_a[i][1];
			k++;
			i++;
		}
		else if(poly_a[i][0] < poly_b[j][0]){
			poly_c[k][0] = poly_b[i][0];
			poly_c[k][1] = poly_b[i][1];
			k++;
			j++;
		}
		else{
			if(poly_b[j][1] +poly_a[i][1]){
				poly_c[k][0] = poly_b[j][0];
			    poly_c[k][1] = poly_b[j][1] + poly_a[i][1];
			    k++;
			}
			i++;
			j++;
		}
	}
	while(i < len_a){
		poly_c[k][0] = poly_a[i][0];
		poly_c[k][1] = poly_a[i][1];
		k++;
		i++;
	}
	while(j < len_b){
		poly_c[k][0] = poly_b[i][0];
		poly_c[k][1] = poly_b[i][1];
		k++;
		j++;
	}
	return k;
}

void display(int poly[][2], int len_c){
	int i;
	printf("\n\nadded polynomial is....\n");
	for(i=0; i<len_c; i++){
		if(poly[i][1] > 0 && i != 0){
			printf("+%d x^%d ", poly[i][1], poly[i][0]);
		}
		else{
			printf("%d x^%d ", poly[i][1], poly[i][0]);
		}
	}
}
