#include <iostream>
using namespace std;

class A{
public:
	int m_pub;
protected:
	int m_pro;
private:
	int m_pri;
};
class B:public A{};
class C:protected A{};
class D:private A{//私有继承,基类的共有成员和保护成员成为子类D的私有成员.
public:
	void foo(void){
		m_pub=10;
		m_pro=10;
		//m_pri=10;//m_pri是基类的私有成员没有被继承下来,因此无法在类的内部使用
	}
};

class X:public B{
public:
	void foo(void){
		m_pub=10;
		m_pro=10;
		//m_pri=10;
	}
}; class Y:public C{ public: void foo(void){
		m_pub=10;
		m_pro=10;
		//m_pri=10;
	}
};
class Z:public D{
public:
	void foo(void){
		//m_pub=10;
		//m_pro=10;
		//m_pri=10;
	}
};

int main(void)
{
	B b;
	b.m_pub;
	//b.m_pro;
	//b.m_pri;
	C c;
	//c.m_pub;
	//c.m_pro;
	//c.m_pri;
	D d;
	//d.m_pub;
	//d.m_pro;
	//d.m_pri;
}







