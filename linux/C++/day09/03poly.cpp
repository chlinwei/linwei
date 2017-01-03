#include <iostream>
using namespace std;

class Base{
public:
	virtual void foo(void)const{
		cout << "Base::foo" << endl;
	}
};
class Derived:public Base{
public:
	void foo(void)const{
		cout << "Derived::foo" << endl;
	}
};
int main(void)
{
	Base* p = new Derived;//向上构造
	p->foo();//子类版本的
	Derived d;
	Base& r = d;//向上构造
	r.foo();
	return 0;
}









