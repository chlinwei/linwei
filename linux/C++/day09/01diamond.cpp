#include <iostream>
using namespace std;

class A{
public:
	A(int data):m_data(data){
		cout << "A::" << this << ","
			<< sizeof(*this) << endl;
	}
	A(const A& that):m_data(that.m_data){}
	A& operator=(const A& that){
		if(&that != this){
			m_data = that.m_data;
		}
		return *this;
	}
protected:
	int m_data;
};
//练习:实现B、C、D类拷贝构造和拷贝赋值函数
//2）虚基类(A)的所有子类（无论是直接的还是间接的）都必须在其构造函数中显示指明该虚基类子对象的构造方式，否则编译器将以缺省方式构造该子对象。
class B:virtual public A{
public:
	B(int data):A(data){
		cout << "B::" << this << ","
			<< sizeof(*this) << endl;
	}
	B(const B& that):A(that){}
	B& operator=(const B& that){
		if(&that != this){
			A::operator=(that);
		}
		return *this;
	}
	void set(int data){
		m_data = data;
	}
};
class C:virtual public A{
public:
	C(int data):A(data){
		cout << "C::" << this << ","
			<< sizeof(*this) << endl;	
	}
	C(const C& that):A(that){}
	C& operator=(const C& that){
		if(&that != this){
			A::operator=(that);
		}
		return *this;
	}
	int get(void){
		return m_data;
	}
};
class D:public B,public C{
public:
	D(int data):B(data),C(data),A(data){
		cout << "D::" << this << ","
			<< sizeof(*this) << endl;	
	}
	D(const D& that):B(that),C(that),A(that){}
	D& operator=(const D& that){
		if(&that != this){
			B::operator=(that);
			C::operator=(that);
		}
	}
};
int main(void)
{
	D d(100);
	cout << d.get() << endl;
	d.set(200);
	cout << d.get() << endl;
	//cout << sizeof(d) << endl;
    D d2 = d;
	cout << d2.get() << endl;
	D d3(300);
	d2 = d3;
	cout << d2.get() << endl;

	return 0;
}
