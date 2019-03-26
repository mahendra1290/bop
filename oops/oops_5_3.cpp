#include<iostream>

using namespace std;

class Array{
    int *arr;
    int len;
    public:
        Array(int len);
        Array(Array &arr1);
        ~Array();
        int binSearch(int val);
        void insertionSort();
        void display();
};

Array::Array(int elemCount){
    int i;
    arr = new int[elemCount];
    len = elemCount;
    cout << "enter "<<len<<" elements"<<endl;
    for(i=0; i<len; i++){
        cin >> arr[i];
    }
}

Array::Array(Array &arr1){
    int i;
    arr = new int[arr1.len];
    len = arr1.len;
    for(i=0; i<len; i++){
        arr[i] = arr1.arr[i];
    }
}

Array::~Array(){
    delete[] arr;
    cout <<"destructor"<<endl;
}

int Array::binSearch(int val){
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

void Array::insertionSort(){
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
    int elemCount;
    cout << "enter number of elements"<<endl;
    cin >> elemCount;
    Array arr_1(elemCount);
    Array arr_2(arr_1);
    arr_1.display();
    arr_1.insertionSort();
    cout<<"binary search result "<<arr_1.binSearch(5)<<endl;
    arr_1.display();
}
