#include<stdio.h>

int b_search(int arr[], int val, int low, int high);

int bin_search(int arr[], int val, int len);

int main(){
    int arr[10] = {1, 2, 3, 4 ,7, 9, 11, 14, 18, 21};
    while(1){
        int val;
        scanf("%d", &val);
        printf("searched %d\n", bin_search(arr, val, 10));
    }
}


int b_search(int arr[], int val, int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        if(arr[mid] == val){
            return mid;
        }
        else if(arr[mid] < val){
            return b_search(arr, val, mid+1, high);
        }
        else{
            return b_search(arr, val, low, mid);
        }
    }
    return -1;
}

int bin_search(int arr[], int val, int len){
    int low=0, high=len, mid;
    while(low < high){
        mid = (low+high)/2;
        if(arr[mid] == val){
            return mid;
        }
        else if(arr[mid] < val){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return -1;
}
