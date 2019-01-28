#include<iostream>

using namespace std;

class Student{
    int roll_no, sem, rankk, pin;
    string name, address, city, branch;
public:
    void add_details();
    friend void get_details(Student arr[], int len);
    void update();
};

void get_details(Student arr[], int len){
    string temp_branch;
    int i, temp_sem, stud_count=0;
    cout << "enter branch: "<<endl;
    getline(cin, temp_branch);
    cout << "enter semester: "<<endl;
    cin >> temp_sem;
    cin.ignore();
    for(i=0; i<len; i++){
        if(arr[i].branch == temp_branch && arr[i].sem == temp_sem){
            stud_count++;
            cout<<"-----------------------"<<endl;
            cout<<stud_count<<"."<<endl;
            cout <<" "<< arr[i].name<<endl;
            cout <<" "<< arr[i].roll_no<<endl;
            cout <<" "<< arr[i].rankk<<endl;
            cout <<" "<< arr[i].address<<endl;
            cout <<" "<< arr[i].city<<endl;
            cout <<" "<< arr[i].pin<<endl;
            cout <<"-----------------------"<<endl;
        }
    }
    if(!stud_count){
        cout << "No student found...."<<endl;
    }
}

void Student::add_details(){
    cout<<"Enter roll no.: ";
    cin >> roll_no;
    cout<<"Enter semester : ";
    cin >> sem;
    cout<<"Enter rank : ";
    cin >> rankk;
    cout<<"Enter name : ";
    getline(cin, name);
    cout<<"Enter branch : ";
    getline(cin, branch);
    cout<<"Enter city : ";
    getline(cin, city);
    cout<<"Enter address : ";
    getline(cin, address);
    cin.ignore();
}

int main(){
    Student cs[3];
    int len=3, i;
    char conti;
    for(i=0; i<len; i++){
        cs[i].add_details();
    }
    while(1){
        get_details(cs, len);
        cout << "want to continue[y|n]?";
        cin >> conti;
        if(conti == 'n' || conti == 'N'){
            cout << "Thanks for using database";
            break;
        }
    }
}
