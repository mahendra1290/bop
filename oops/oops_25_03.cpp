#include<iostream>

using namespace std;

class Distance{
    int dist;
    public:
        Distance(int distance=0);
        Distance operator -(const Distance dist_1);
        friend ostream &operator<<(ostream &output, const Distance &D){
	    output << D.dist;
	    return output;
	    }
};

Distance::Distance(int distan){
    dist = distan;
}

Distance Distance::operator -(const Distance dist_1){
    Distance dist_3;
    dist_3.dist = dist-dist_1.dist;
    return dist_3;
}

int main(){
    Distance d_1(10), d_2(5), d_3(0);
    d_3 = d_1-d_2;
    cout<<d_3;
}
