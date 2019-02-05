#include<stdio.h>

int main(){
    int sum=0, i, k, num_count;
    float average = 0;
    printf("How many numbers are there ? ");
    scanf("%d", &num_count);
    int arr[num_count];
    for(i=0; i<num_count; i++){
        scanf("%d", arr+i);
        sum += *(arr+i);
    }
    average = (float)sum/num_count;
    printf("average is %.2f", average);
}
