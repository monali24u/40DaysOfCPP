//Factory pattern

#include <iostream>
using namespace std;

enum VehicleType {
    VT_TwoWheeler,
    VT_FourWheeler
};

class vehicle
{
	public:
	   virtual void print() = 0;
	   static vehicle* Create(VehicleType type);
};

class TwoWheeler : public vehicle
{
	public:
	  void print()
	  {
	  	cout << "I am two wheeler" << endl;
	  }
};

class FourWheeler : public vehicle
{
	public:
	  void print()
	  {
	  	cout<<"I am four wheeler"<<endl;
	  }
};

vehicle* vehicle::Create(VehicleType type)
{
	if (type == VT_TwoWheeler)
        return new TwoWheeler();
    else if (type == VT_FourWheeler)
        return new FourWheeler();
    else return NULL;
}

int main() {

	TwoWheeler *tw = (TwoWheeler*)vehicle::Create(VT_TwoWheeler);
	tw->print();

	return 0;
}
