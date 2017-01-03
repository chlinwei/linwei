#include <iostream>
using namespace std;

class A{
	virtual void foo(void){}
};
class B:public A{
	void foo(void){}
};
class C:public A{
	void foo(void){}
};
class D{};

int main(void)
{
	B b;
	A* pa = &b;
	cout << pa << endl;
	//B* pb = pa;
	B* pb = dynamic_cast<B*>(pa);//pa是基类指针,显然能转化成子类的指针
	cout << pb << endl;

	//转换失败，返回NULL
	C* pc = dynamic_cast<C*>(pa);//pa现在是B*类型的不是基类指针,转换失败
	cout << pc << endl;

	D* pd = dynamic_cast<D*>(pa);
	cout << pd << endl;

	//引用转换，抛出异常
	A& ra = b;
	C& rc = dynamic_cast<C&>(ra);
	return 0;
}
