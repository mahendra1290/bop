#include<stdio.h>

int horner_eval(int poly[], int x, int i, int len);

int main(){
    int poly[5] = {7, 5, 4, 3, 2};
    //array index is the represents the power
    int ans = 0;
    ans = horner_eval(poly, 1, 0, 5);
    printf("%d", ans);
    return 0;
}


int horner_eval(int poly[], int x, int i, int len){
    if(i > len){
        return 0;
    }
    return poly[i]+x*(horner_eval(poly, x, ++i, len));
}
