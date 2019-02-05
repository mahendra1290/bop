#include<stdio.h>
#include<stdlib.h>

int main(){
    int *arr;
    int maxx_0=0, maxx_1=0, i, num_count;
    scanf("%d", &num_count);
    arr = (int *)malloc(num_count*sizeof(int));
    for(i=0; i<num_count; i++){
        scanf("%d", &arr[i]);
        if(arr[i]>maxx_0){
            maxx_0 = arr[i];
        }
    }
    for(i=0; i<num_count; i++){
        if(arr[i]>maxx_1 && arr[i]<maxx_0){
            maxx_1 = arr[i];
        }
    }
    printf("largest number is %d\nsecond largest number is %d",maxx_0, maxx_1);
}
