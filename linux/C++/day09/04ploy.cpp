#include <iostream>
using namespace std;
class A{};
class B:public A{};
class Base{
public:
	virtual void foo(void){
		cout << "Base::foo" << endl;
	}
	virtual void bar(void){
		cout << "Base::bar" << endl;
	}
	virtual void hum(int){}
	virtual A* func(void){
		cout << "Base::func" << endl;
	}
	virtual void pub(void){
		cout << "Base::pub" << endl;
	}
};
class Derived:public Base{
public:
	virtual void foo(void){//重写
		cout <<"Derived::foo" << endl; 
	}
	void bar(int x){
		cout << "Derived::bar" << endl;
	}
	void bar(void)const{
		cout << "Derived::bar2" << endl;
	}
	//int hum(int){}
	int hum(void){}
	B* func(void){ //想要形成覆盖版本,必须具有函数相同的标签,
		//即函数名,参数列表和常属性
		//如果基类中虚函数的返回类型不是指针或者引用,则之类
		//想要形成覆盖版本,则之类中相应的函数的返回类型一定要一样
		//如果基类中的虚函数的返回类类型是指针或者引用,那么允许之类返回
		//子类的指针或者引用

		cout << "Derived::func" << endl;
	}
private:
	void pub(void){
		cout << "Derived::pub" << endl;
	}
};
int main(void)
{
	Derived d;
	Base& b = d;//向上构造,必须通过指针或者引用才能表现出多态
	b.foo();
	b.bar();
	b.func();
	b.pub();
	return 0;
}
