//sorting algorithms

#include<stdio.h>

void selection(int arr[], int len, int reverse);

void insertion(int arr[], int len, int reverse);

void merge_sort(int arr[], int start, int end, int reverse);

void merge_norecur(int arr[], int start, int end);

void quick(int arr[], int start, int end);

void merge(int arr[], int start, int mid, int end, int reverse);

void method_select(int arr[], int len);

void swap(int *x, int *y);

int main(){
    int i, len;
    printf("Sorting algorithm tester\n");
    printf("------------------------\n");
    char conti = 'y';
    while(conti == 'y'){
        printf("Enter the number of elements: ");
        scanf("%d", &len);
        int arr[len];
        for(i=0; i<len; i++){
            scanf("%d", &arr[i]);
        }
        method_select(arr, len);       //function to select sorting method
        printf("\nwant to do more [y/n]? ");
        scanf(" %c", &conti);
        if(conti == 'n' || conti == 'N'){
            break;
        }
    }
    printf("Thanks for testing\n");
    return 0;
}

void selection(int arr[], int len, int reverse){
    // rev = 0 for normal & rev = 1 for sort in reverse...
    int i, j, index;
    for(i=0; i<len-1; i++){
        index = i;
        for(j=i+1; j<len; j++){
            if(!reverse && arr[j] < arr[index]){
                index = j;
            }
            else if(reverse && arr[j] > arr[index]){
                index = j;
            }
        }
        swap(&arr[i], &arr[index]);
    }
}

void insertion(int arr[], int len, int reverse){
    // rev = 0 for normal & rev = 1 for sort in reverse...
    int i, j, elem;
    for(i=1; i<len; i++){
        j = i-1;
        elem = arr[i];
        if(!reverse){
            while(j>=0 && arr[j] > elem){
                arr[j+1] = arr[j];
                j--;
            }
        }
        else{
            while(j>=0 && arr[j] < elem){
                arr[j+1] = arr[j];
                j--;
            }
        }
        arr[j+1] = elem;
    }
}

void merge_sort(int arr[], int start, int end, int reverse){
    //reverse = 0 for normal reverse = 1 for sort in reverse....
    //end is last index and start is first
    int mid = (start+end)/2;
    if(start==end){
        return;
    }
    merge_sort(arr, start, mid, reverse);
    merge_sort(arr, mid+1, end, reverse);
    merge(arr, start, mid, end, reverse);
}

void merge(int arr[], int start, int mid, int end, int reverse){
    int len, i = start, j = mid+1, k = 0;
    len = end-start+1;
    int temp[len];
    while(i <= mid && j <= end){
        if(arr[j] < arr[i]){
            if(reverse){
                temp[k] = arr[i++];
            }
            else{
                temp[k] = arr[j++];
            }
        }
        else{
            if(reverse){
                temp[k] = arr[j++];
            }
            else{
                temp[k] = arr[i++];
            }
        }
        k++;
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= end){
        temp[k++] = arr[j++];
    }
    for(i=start; i<=end; i++){
        arr[i] = temp[i-start];
    }
}

void quick(int arr[], int start, int end){
    if(start < end){
        int pivot = arr[start];
        int i=start, j=end+1;
        while(i < j){
            do{
                i++;
            }
            while(arr[i] < pivot && i<=end);
            do{
                j--;
            }
            while(arr[j] > pivot);
            if(i < j){
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[start], &arr[j]);
        quick(arr, start, j-1);
        quick(arr, j+1, end);
    }
}

void merge_norecur(int arr[], int start, int end){
    //it merges 2 element list then 4, 8, 16......
    int i, j, k, mid;           //i for start and j is for end
    int len = end-start+1;      //length of list
    int group = 1;              //how many element in one iteration is 2*group
    while(group < len){
        for(i=0; i<end; i+=2*group){
            //i is starting index according to
            //size of list to be merged

            j = i+2*group-1;    //end of list
            if(j > end){        //to check if j is in limit
                j = end;
            }
            mid = i+group-1;    //mid of list
            merge(arr, i, mid, j, 0);
        }
        group = 2*group;
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void method_select(int arr[], int len){
    int method, i;
    printf("Select the sorting algo\n");
    printf("1. selection sort\n");
    printf("2. insertion sort\n");
    printf("3. merge sort\n");
    printf("4. quick sort\n");
    printf("5. iterative merge sort\n");
    scanf("%d", &method);
    switch(method){
        case 1:
            selection(arr, len, 0);
            printf("\nsorted by selection sort\n");
            break;
        case 2:
            insertion(arr, len, 0);
            printf("\nsorted by insertion sort\n");
            break;
        case 3:
            merge_sort(arr, 0, len-1, 0);
            printf("\nsorted by merge sort\n");
            break;
        case 4:
            quick(arr, 0, len-1);
            printf("\nsorted by quick sort\n");
            break;
        case 5:
            merge_norecur(arr, 0, len-1);
            printf("\nsorted by iterative mergesort\n");
            break;
        default:
            merge_sort(arr, 0, len-1, 0);
            printf("\nsorted by merge sort\n");
            break;
    }
    for(i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
