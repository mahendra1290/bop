#include<iostream>

using namespace std;

template<class T>

class vector{
    T a;
    T b;
    public:
    vector(T x, T y){
        a = x;
        b = y;
        cout << "a+b "<<a+b;
    }
};

int main(){
    vector <float> vec(8.6, 8);
}
