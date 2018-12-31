#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){

    printf("Welcome\n");
    printf("This simple program does normal operation on complex number\n");
    int complex_1[2] = {0, 0};
    int complex_2[2] = {0, 0};
    complex_inp(complex_1);
    printf("%d %d", complex_1[0], complex_1[1]);
}

void complex_inp(int comp_cord[]){
    char comp_point[10];
    int got_sign = 0;
    char str[2] = {' ',' '};
    int oprt[2] = {1, 1};
    int j = 0;
    int i = 0;
    int real=0;
    int imag=0;
    int len;
    printf("Enter the complex point in form a+ib: \n");
    scanf("%s", comp_point);
    len = strlen(comp_point);
    int index_i = len;
    int for_real = index_i;

    for(i=0; i<len; i++){
        if(comp_point[i] == 'i'){
            index_i = i;
            for_real = i-1;
        }
        if(comp_point[i] == '-' || comp_point[i] == '+'){
            if(i != 0){
                j++;
            }
            if(i == 0){
                got_sign = 1;
            }
            str[j] = comp_point[i];
            j++;
        }
    }
    for(i=got_sign; i<for_real; i++){
        real = real*10 + (comp_point[i]-48);
    }
    for(i=index_i+1; i<len; i++){
        imag = imag*10 + (comp_point[i]-48);
    }
    printf("got sign %d and i index %d\n", got_sign, index_i);
    if(str[0] == '-' || index_i == len){
         real *= -1;
    }

    comp_cord[0] = real;
    comp_cord[1] = imag;
}
