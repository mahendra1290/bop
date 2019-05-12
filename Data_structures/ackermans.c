#include<stdio.h>

int ackerman(int m, int n);

int main(){
    
    return 0;
}

int ackerman(int m, int n){
    if (m == 0){
        return n+1;
    }
    while (m){
        if (n == 0){
            n = 1;
            m -= 1;
        }
    }
}