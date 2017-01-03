#include <iostream>
using namespace std;
#include <typeinfo>
#include <cstring>

class X{
	virtual void foo(){}
};
class Y:public X{
	void foo(){}
};
class Z:public X{
	void foo(){}
};
void func(X& x){
	if(typeid(x) == typeid(Y)){
	//if(!strcmp(typeid(x).name(),"1Y")){
		cout << "这是一个Y对象" << endl;
	} 
	if(typeid(x) == typeid(Z)){
	//if(!strcmp(typeid(x).name(),"1Z")){
		cout << "这是一个Z对象" << endl;
	}
};

int main(void)
{
	int x;
	cout << typeid(x).name() << endl;//i
	cout << typeid(char).name() << endl;//c
	cout << typeid(unsigned int).name()
	   	<< endl;//j
	cout << typeid(double[100]).name()
		<< endl;//A100_d
	cout << typeid(int* [5]).name()
		<< endl;//A5_Pi
	cout << typeid(int(*)[10]).name()
		<< endl;//PA10_i
	cout <<
		typeid(int(*)(unsigned char*)).name()
		<< endl;//PFiPhE
	cout <<
		typeid(int(*[5])(void)).name()
		<< endl;//A5_PFivE
	X* px = new Y;
	cout << typeid(*px).name() << endl;//1Y

	Y y;
	Z z;
	func(y);
	func(z);
	return 0;
}





