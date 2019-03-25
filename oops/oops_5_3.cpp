#include<iostream>

using namespace std;

class Array{
    int *arr;
    int len;
    public:
        Array(int len);
        Array(Array &arr1);
        ~Array();
        int bin_search(int val);
        void insertion();
        void display();
};

Array::Array(int elemCount){
    int i;
    arr = new int[elemCount];
    len = elemCount;
    cout << "enter elements"<<endl;
    for(i=0; i<len; i++){
        cin >> arr[i];
    }
}

Array::Array(Array &arr1){
    int i;
    //cout <<arr1.len<<endl;
    arr = new int[arr1.len];
    len = arr1.len;
    for(i=0; i<len; i++){
        arr[i] = arr1.arr[i];
    }
}

Array::~Array(){
    cout <<"destructor"<<endl;
}

int Array::bin_search(int val){
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

void Array::insertion(){
        // rev = 0 for normal & rev = 1 for sort in reverse...
    int i, j, elem;
    for(i=1; i<len; i++){
        j = i-1;
        elem = arr[i];
        while(j>=0 && arr[j] > elem){
                arr[j+1] = arr[j];
                j--;
        }
        arr[j+1] = elem;
    }
}

void Array::display(){
    int i;
    for(i=0; i<len; i++){
        cout << arr[i] << " ";  
    }
    cout <<endl;
}
int main(){
    Array arr_1(10);
    Array arr_2(arr_1);
    arr_1.display();
    arr_1.insertion();
    arr_1.display();
}
