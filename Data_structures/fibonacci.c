#include <stdio.h>

long int getFibonacci(int n);

long int getFibonacciByRec(long int n_1, long int n_0, int n);

int main(){
    printf("%ld", getFibonacciByRec(1, 0, 92));
    return 0;
}

long int getFibonacciByRec(long int n_1, long int n_0, int n){
    long int fibo = n_1+n_0;
    if (n <= 2){
        return fibo;
    }
    return getFibonacciByRec(fibo, n_1, --n);
}

long int getFibonacci(int n){
    int i;
    long int temp_1  = 0;
    long int temp_2  = 1;
    long int temp_3  = 0;
    for (i = 2; i<= n; i++){
        temp_3 = temp_2+temp_1;
        temp_1 = temp_2;
        temp_2 = temp_3;
    }
    return temp_3;
}
