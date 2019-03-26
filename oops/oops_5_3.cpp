#include<iostream>

using namespace std;

class Array{
    int *arr;
    int len;
    public:
        Array(int len);
        Array(Array &arr1);
        ~Array();
<<<<<<< HEAD
        int binSearch(int val);
        void insertionSort();
=======
        int bin_search(int val);
        void insertion();
>>>>>>> a23d6a24874480ddeec370c6e98b130624f1b6ef
        void display();
};

Array::Array(int elemCount){
    int i;
    arr = new int[elemCount];
    len = elemCount;
<<<<<<< HEAD
    cout << "enter "<<len<<" elements"<<endl;
=======
    cout << "enter elements"<<endl;
>>>>>>> a23d6a24874480ddeec370c6e98b130624f1b6ef
    for(i=0; i<len; i++){
        cin >> arr[i];
    }
}

Array::Array(Array &arr1){
    int i;
<<<<<<< HEAD
=======
    //cout <<arr1.len<<endl;
>>>>>>> a23d6a24874480ddeec370c6e98b130624f1b6ef
    arr = new int[arr1.len];
    len = arr1.len;
    for(i=0; i<len; i++){
        arr[i] = arr1.arr[i];
    }
}

Array::~Array(){
<<<<<<< HEAD
    delete[] arr;
    cout <<"destructor"<<endl;
}

int Array::binSearch(int val){
=======
    cout <<"destructor"<<endl;
}

int Array::bin_search(int val){
>>>>>>> a23d6a24874480ddeec370c6e98b130624f1b6ef
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

<<<<<<< HEAD
void Array::insertionSort(){
=======
void Array::insertion(){
        // rev = 0 for normal & rev = 1 for sort in reverse...
>>>>>>> a23d6a24874480ddeec370c6e98b130624f1b6ef
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
<<<<<<< HEAD
    int elemCount;
    cout << "enter number of elements"<<endl;
    cin >> elemCount;
    Array arr_1(elemCount);
    Array arr_2(arr_1);
    arr_1.display();
    arr_1.insertionSort();
    cout<<"binary search result "<<arr_1.binSearch(5)<<endl;
=======
    Array arr_1(10);
    Array arr_2(arr_1);
    arr_1.display();
    arr_1.insertion();
>>>>>>> a23d6a24874480ddeec370c6e98b130624f1b6ef
    arr_1.display();
}
