#include<iostream>
using namespace std;

class Complex{
    float real;
    float imag;
public:
	Complex(float real, float imag);
	Complex();
	//normal operator overloading
	Complex operator+(Complex comp1);
	Complex operator-(Complex comp1);
	Complex operator*(Complex comp1);
	Complex operator/(Complex comp1);
	//compound operator overloading
	void operator+=(Complex comp1);
	void operator-=(Complex comp1);
	void operator*=(Complex comp1);
	void operator/=(Complex comp1);
	friend ostream &operator<<( ostream &output, const Complex &comp);
	void operator()(float real, float imag);
};

Complex::Complex(){
    real = 0.0;
    imag = 0.0;
}

Complex::Complex(float real, float imag){
    this->real = real;
    this->imag = imag;
}

Complex Complex::operator+(Complex comp1){
    Complex ans;
    ans.real = real+comp1.real;
    ans.imag = imag+comp1.imag;
    return ans;
}

void Complex::operator+=(Complex comp1){
    real = real+comp1.real;
    imag = imag+comp1.imag;
}

Complex Complex::operator-(Complex comp1){
    Complex ans;
    ans.real = real-comp1.real;
    ans.imag = imag-comp1.imag;
    return ans;
}

void Complex::operator-=(Complex comp1){
	real = real-comp1.real;
    imag = imag-comp1.imag;
}

Complex Complex::operator*(Complex comp1){
    Complex ans;
    ans.real = (real*comp1.real)-(imag*comp1.imag);
    ans.imag = (real*comp1.imag)+(imag*comp1.real);
    return ans;
}

void Complex::operator*=(Complex comp1){
    real = (real*comp1.real)-(imag*comp1.imag);
    imag = (real*comp1.imag)+(imag*comp1.real);
}
Complex Complex::operator/(Complex comp1){
    Complex ans;
    ans.real = ((real*comp1.real)+imag+comp1.imag)/((real*real) + (imag*imag));
    ans.imag = ((imag*comp1.real)-(real*comp1.imag))/
			   (comp1.real*comp1.real*comp1.imag*comp1.imag);
    return ans;
}
void Complex::operator/=(Complex comp1){
    real = ((real*comp1.real)+imag+comp1.imag)/((real*real) + (imag*imag));
    imag = ((imag*comp1.real)-(real*comp1.imag))/
			   (comp1.real*comp1.real*comp1.imag*comp1.imag);
}

void Complex::operator()(float real, float imag){
	///to update the value of complex number
    this->real = real;
    this->imag = imag;
}
ostream &operator<<( ostream &output, const Complex &comp){
	if(comp.imag >= 0){
		output << comp.real <<" +" <<comp.imag<<"i";
	}
	else{
		output << comp.real <<" " <<comp.imag<<"i";
	}
	return output;
}

int main(){
	Complex comp_1(2.4, 4.1), comp_2(2.2, -5.4), comp_3;
	cout << "comp 1 : "<<comp_1<<endl;
	cout << "comp 2 : "<<comp_2<<endl;
	cout << "comp 3 : "<<comp_3<<endl;
	comp_3 = comp_1+comp_2;
	cout << "addition comp 3 : "<<comp_3<<endl;
	comp_3 = comp_1-comp_2;
	cout << "subtraction comp 3 : "<<comp_3<<endl;
	comp_3 = comp_1*comp_2;
	cout << "multiply comp 3 : "<<comp_3<<endl;
	comp_3 = comp_1/comp_2;
	cout << "divide comp 3 : "<<comp_3<<endl;
	comp_3 += comp_1;
	cout << "compound addition comp 3 : "<<comp_3<<endl;
	comp_3(4.5, 8.9);
	cout << "parenthesis comp 3 : "<<comp_3<<endl;
    return 0;
}
