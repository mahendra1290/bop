//heapsort
//mahendra suthar
//date: 8-4-19

#include <stdio.h>

int min(int x, int y);

void heapsort(int *arr, int len);

void swap(int *x, int *y);

void adjust(int *arr, int i, int n){
    int left = 2*i;
    int right = 2*i+1;
    int index;
    while(left <= n && right <= n){
        if(arr[left-1] > arr[right-1]){
            index = left;
        }
        else{
            index = right;
        }
        if(arr[index-1] > arr[i-1]){
            swap(&arr[index-1], &arr[i-1]);
        }
        i = index;
        left = 2*i;
        right = 2*i+1;
    }
    if(left <= n){
        if(arr[left-1] > arr[i-1]){
            swap(&arr[left-1], &arr[i-1]);
        }
    }
    else if(right <= n){
        if(arr[right-1] > arr[i-1]){
            swap(&arr[right-1], &arr[i-1]);
        }
    }
}

int main(){
    int arr[] = {-8, 20, 78 ,4, 1, 0, 11, 12, 10, 9 , 6, 7};
    heapsort(arr, 12);
    for(int i=0; i<12; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void heapsort(int *arr, int len){
    int n = len;
    if(n == len){
        for(int i=n/2; i>=1; i--){
            adjust(arr, i, n);
        }
    }
    while(n>1){
        swap(&arr[0], &arr[n-1]);
        adjust(arr, 1, n-1);
        n = n-1;
    }
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int min(int x, int y){
    if(x < y)
        return x;
    return y;
}