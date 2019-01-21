#include<stdio.h>

void merge(long int a[],long int l[],long int lt[],long int r[],long int rt[],long int t[], int len_l, int len_r);
void mergesort(long int arr[], long int tmp[], int start, int end);

void mergesort(long int arr[], long int tmp[], int start, int end){
	if(end-start <= 1){                      //checks if only one item is left in list
		return NULL;
	}
	else{
	int mid = (end-start)/2;                 //split list from start-mid and mid-end
	long int left[mid];                           //left part
	long int right[end-mid];
	long int left_t[mid];
	long int right_t[mid];                      //right part
	    for(int i=0; i<mid; i++){            //creating left part
		left[i] = arr[i];
		left_t[i] = tmp[i];
	    }
	for(int i=0; i<end-mid; i++){            //creating right part
		right[i] = arr[i+mid];
		right_t[i] = tmp[i+mid];
	    }
	mergesort(left, left_t, start, mid);             //reccursively calling
	mergesort(right, right_t, start, end-mid);
	merge(arr, left, left_t, right, right_t, tmp, mid, end-mid);
    }
}

void merge(long int a[],long int l[],long int lt[],long int r[],long int rt[],long int t[], int len_l, int len_r){
	int k = len_l + len_r;                   //length of our merged array
	int i=0,j=0,x=0;                         //i and j are index for left and right respectively
	while(x < k && (i<len_l && j<len_r)){    //iterating until we have completed our merged arrays
		if(l[i] < r[j]){                     //checks if left side item is smaller than right
			a[x] = l[i];
			t[x] = lt[i];
			i++;
		}
		else{                                //checks if right side item is smaller than left
			a[x] = r[j];
			t[x] = rt[j];
			j++;
		}
		x++;
	    if(i == len_l){                      //if left list is already sorted
	    	for(int az=j; az<len_r; az++){
	    	a[x] = r[az];
	    	t[x] = rt[az];
	    	x++;
	        }
		}
		else if(j == len_r){                 //if right is completely sorted
			for(int az=i; az<len_l; az++){
	    	a[x] = l[az];
	    	t[x] = lt[az];
	    	x++;
	        }
	    }
	}
}

int main(){
    int i;
    long int totl_km=0;
    long int days=0, temp=0, rem, quot;
    long int distance, km_day;
    int diff;
    scanf("%ld %ld %d", &distance, &km_day, &diff);
    long int day[diff];
    long int  km[diff];
    for(i=0; i<diff; i++){
        //printf("frst %d\n", i);
        scanf("%ld %ld", &day[i], &km[i]);
    }
    temp = 0;
    mergesort(day, km, 0, diff);
    for(i=0; i<diff; i++){
        days += (day[i]-1-temp);
        totl_km += km_day*(day[i]-1-temp);
        printf("tptl %ld\n", totl_km);
        printf("days %ld\n", days);
        if(totl_km >= distance){
            break;
        }
        totl_km += km[i];
        days += 1;
        temp = day[i];
        if(totl_km >= distance){
            break;
        }
        printf("aft tptl %ld\n", totl_km);
        printf("aft days %ld\n", days);
    }
    while(totl_km < distance){
        totl_km += km_day;
        days += 1;
    }
    //printf("%ld\n", day[2]);
    printf("%ld", days);
    return 0;
}
