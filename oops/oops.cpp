#include<iostream>
#include<gtk/gtk.h>
#define MAX 50
using namespace std;

class Stack{
    private:
        int sizee;
        int top;
        int *arr = NULL;
        int elem;
    public:
        Stack(int len);
        void push(int val);
        int pop();
        bool isStackFull();
        bool isStackEmpty();
};
Stack::Stack(int len){
    sizee = len;
    top   = -1;
    elem  = 0;
    arr   = new int[len];
    if(arr == NULL){
        cout<<"ERROR: can't create stack";
    }
}

void Stack::push(int val){
    if(top < sizee-1 && !isStackFull()){
        arr[++top] = val;
    }
    else{
        cout << "stack is full"<<endl;
    }
}

int Stack::pop(){
    if(top > -1 && !isStackEmpty()){
        return arr[top--];
    }
    else{
        cout << "stack is empty"<<endl;                                             
        return 9999;
    }
}

bool Stack::isStackEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}

bool Stack::isStackFull(){
    if(top == sizee-1){
        return true;
    }
    return false;
}

int main(){
    int i, elem;
    Stack mineStack(10);
    for(i=0; i<13; i++){
        cout<<"enter value: ";
        cin >> elem;
        mineStack.push(elem);
    }
    for(i=0; i<13; i++){
        elem = mineStack.pop();
        cout <<"popped: "<<elem<<endl;
    }
    return 1;
}
