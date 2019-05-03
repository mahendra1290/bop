#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int isSumOfDiv(int num);

int main(){
    for (int i=1; i<9999999; i++){
        if (isSumOfDiv(i)){
            printf ("%d ", i);
        }
    }
    return 0;
}

int isSumOfDiv(int num){
    int sum = 0;
    int i = 0;
    int temp = 0;
    int sqr = sqrt(num);
    for (i=1; i<=sqr; i++){
        if (num%i == 0){
            temp = num/i;
            sum += i;
            if (temp != num){
                sum += temp;
            }
            //printf("div_1 %d & div_2 %d\n", i, temp);
        }
    }
    if (sum == num){
        return 1;
    }
    return 0;
}

