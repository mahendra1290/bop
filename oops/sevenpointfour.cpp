#include <iostream>

using namespace std;

class Set
{
    int *set;
    int currSize;
    int maxSize;
    public:
        Set(int setSize=100);
        void insert(int val);
        void print();
        Set getIntersection(Set b);
        Set getUnion(Set b);
};

Set::Set(int setSize){
    set = new int[setSize];
    maxSize = setSize;
    currSize = 0;
}

void Set::insert(int val){
    if(currSize < maxSize){
        set[currSize++] = val;
    }
    else{
        cout<<"set is full cant add more"<<endl;
    }
}

void Set::print(){
    for(int i=0; i<currSize; i++){
        cout << set[i] <<" ";
    }
    cout <<endl;
}

Set Set::getIntersection(Set b){
    Set c;
    for(int i=0; i<currSize; i++){
        for(int j=0; j<b.currSize; j++){
            if(set[i] == b.set[j]){
                c.insert(set[i]);
            }
        }
    }
    return c;
}

Set Set::getUnion(Set b){
    int i, j;
    Set c;
    for(i=0; i<currSize; i++){
        c.insert(set[i]);
    }
    for(i=0; i<b.currSize; i++){
        for(j=0; j<c.currSize; j++){
            if(b.set[i] == c.set[j])
                break;
        }
        if(j == c.currSize)
            c.insert(b.set[i]);
    }
    return c;
}
int main(){
    Set a, b, c, d;
    int i, j;
    for(i =0; i<20; i++){
        a.insert(i);
        b.insert(i+10);
    }
    a.print();
    b.print();
    c = a.getIntersection(b);
    c.print();
    d = a.getUnion(b);
    d.print();
}