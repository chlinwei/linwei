#include <iostream>
using namespace std;

class A{
public:
	void foo(void){
		cout << "A::foo()" << endl;
	}
	int m_data;
};
class B{
public:
	void foo(int i){
		cout << "B::foo(int)" << endl;
	}
	typedef int m_data;
};
class C:public A,public B{
public:
	using A::foo;
	using B::foo;
};
int main(void)
{
	C c;
	c.foo();
	c.foo(10);
	c.A::m_data = 10;
	C::B::m_data i = 20;
	cout << c.A::m_data << endl;
	cout << i << endl;
	return 0;
}










