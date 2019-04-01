#include<iostream>

using namespace std;

class Beta{
    public:
        int beta;
        Beta(int a){
            beta = a;
            cout << "beta constructor "<< beta<<endl;
        }
};

class  Alpha{
    public:
        int alpha;    
        Alpha(int b, int c){
            alpha = b+c;
            cout << "alpha constructor "<< alpha<<endl;
        }
};

class  Gamma{
    public:
        int x;
        int y;
        int print(){
            cout << "x is "<<x" y is "<< y<<endl;
        }
        Gamma(int a, int b):{
            x = a;
            y = b;
            cout <<"gamma constructor "<< "x is "<<x<<" y is "<<y<<endl;
        }
};

int main(){
    Gamma gam(1, 2);
}
