#include <iostream>
using namespace std;

class Base{
public:
	Base(void){
		this->func();
	}
	~Base(void){
		this->func();
	}
	virtual int cal(int x,int y){
		return x+y;
	}
	void foo(void){//void foo(Base* this)
		bar();//this->bar();
	}
	virtual void bar(void){
		cout << "Base::bar()" << endl;
	}
	virtual void func(void){
		cout << "Base::func" << endl;
	}
};
class Derived:public Base{
	int cal(int a,int b){
		return a*b;
	}
	void bar(void){
		cout << "Derived::bar()" << endl;
	}
	void func(void){
		cout << "Derived::func" << endl;
	}
};
int main(void)
{
	//多态概念,如果基类中的某个成员函数申明为
	//虚函数,之类中有相应的覆盖,
	//这时通过指向之类对象的基类指针或者引用(即向上构造),调用的基类虚函数
	//实际调用的是之类的覆盖版本
	Derived d;
	Base b = d;//这里是简单的赋值,并不是向上构造,不会形成多态
	//所以b.cal(100,200)调用的还是原始的版本
	cout << b.cal(100,200) << endl;//300
//	d.foo();//foo(&d); Base* this = &d
	return 0;
}
