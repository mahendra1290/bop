#include<iostream>

using namespace std;

class Fraction{
    float frac;
public:
	Fraction(){
		///normal constructor
	    frac = 0.0;
	}
	Fraction(int p, int q){
		///fraction in p/q form
	    frac = float(p/q);
	}
	friend ostream &operator<<(ostream &output, const Fraction &D){
	    output << D.frac;
	    return output;
	}
	void operator = (float f);
	void operator *=(int i);
	void operator *=(Fraction);
	void operator *=(float f);
	void operator *=(double db);

};

void Fraction::operator =(float f){
	///to assign value of fraction
    frac = f;
}

void Fraction::operator *= (int i){
	///to compound multiply integer
    frac = frac*i;
}

void Fraction::operator *=(Fraction target){
	///to compound multiply Fraction object
    frac = frac * target.frac;
}

void Fraction::operator *=(float f){
	///to compound multiply float
    frac = frac * f;
}

void Fraction::operator *=(double db){
	///to compound multiply double
    frac = frac*db;
}

int main(){
    Fraction f1, f2, f3;
    f1 = 2.2;
    f2 = 3.9;
    f3 = 4.2;
    cout <<"fraction f1 : "<< f1 <<endl;
    cout <<"fraction f2 : "<< f2 <<endl;
    cout <<"fraction f3 : "<< f3 <<endl;
    f1 *= 3;
    f2 *= 6.4;
    f3 *= f1;
    cout <<"fraction f1 : "<< f1 <<endl;
    cout <<"fraction f2 : "<< f2 <<endl;
    cout <<"fraction f3 : "<< f3 <<endl;
}
