
#include <iostream>
using namespace std;

class Base{
public:
	Base(void){
		cout << "Base::Base()" << endl;
	}
	//虚析构函数
	//
	 virtual ~Base(void){
		cout << "Base::~Base()" << endl;
	}
};
class Derived:public Base{
public:
	Derived(void){
		cout << "Derived::Derived()" << endl; } ~Derived(void){
		cout << "Derived::~Derived()" << endl;
	}
};
int main(void)
{
	Base* pb = new Derived;
	//new Derived时,Derived继承的是Base所以
	//会先调用Base的构造函数在调用Derived的构造函数
	delete pb;//如果Base的析构函数没有加virtual函数时,则只是会调用
	//Base的析构函数,而不会调用Derived的析构函数,
	//如果Base的析构函数是虚析构函数时,则调用的是Derived的析构函数
	//又因为,Derived是继承Base的所以会再次调用Base的析构函数
	return 0;
}
