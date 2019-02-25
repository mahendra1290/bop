#include<iostream>
using namespace std;

class Bikeshop;
class Bicycle;

class BikeShop{
    private:
    	int gears;
	public:
		BikeShop(int maxx_gear=6){
		    gears = maxx_gear;
		}
		friend void update(BikeShop, Bicycle &);
};

class Bicycle{
	private:
		int speed;
		int gear;
		int max_gears;
	public:
		Bicycle(int max_gears);
		Bicycle();
		void increSpeed(int incre);
		void brake(int decre);
		void upGear();
		void downGear();
		friend void update(BikeShop shop, Bicycle &bike);
		friend void showSpeed(Bicycle hero);
		friend bool operator==(Bicycle bike_1, Bicycle bike_2);
		friend ostream &operator<<(ostream &output, const Bicycle &bike);
};

void update(BikeShop shop, Bicycle &bike){
    bike.max_gears = shop.gears;
}

Bicycle::Bicycle(){
    speed     = 0;
    gear      = 1;
    max_gears = 6;
}

Bicycle::Bicycle(int max_gears){
	speed     = 0;
    gear      = 1;
    this->max_gears = max_gears;
}

void Bicycle::increSpeed(int incre=1){
    speed += incre;
}

void Bicycle::brake(int decre=1){
    speed -= decre;
    if(speed < 0){
		speed = 0;
    }
}

void Bicycle::upGear(){
    if(gear++ < max_gears);
}

void Bicycle::downGear(){
    if(gear-- > 2);
}
void showSpeed(Bicycle hero){
    cout <<"current speed "<<hero.speed<<" m/s"<<endl;
}

bool operator==(Bicycle bike_1, Bicycle bike_2){
    if(bike_1.speed == bike_2.speed){
		return true;
    }
    else{
		return false;
    }
}

ostream &operator<<(ostream &output, const Bicycle &bike){
    output <<"current speed : "<<bike.speed<<" m/s"<<endl<<
    "gear : "<<bike.gear<<endl<<"max gears : "<<bike.max_gears<<endl;
    return output;
}

int main(){
	BikeShop nexa(7);
	Bicycle hero, bmw(10);
	cout << bmw <<endl;
	cout << hero <<endl;
	bmw.increSpeed();
	update(nexa, hero);
	cout << bmw <<endl;
	cout << hero <<endl;
	if(bmw == hero){
		cout << "yess"<<endl;
	}
    return 0;
}
