#include <iostream>
using namespace std;

class Base{
public:
	Base(void):m_i(0){}
	Base(int i):m_i(i){}
	int m_i;
};
class Derived:public Base{
public:
	Derived(void):m_i(0){}
	Derived(int i,int j):Base(i),m_i(j){}
	Derived(const Derived& that)://拷贝构造函数
		m_i(that.m_i),Base(that){}//这里Base(int i):类类型转化成int类型了
	Derived& operator=(const Derived& that){
		if(&that != this){
			m_i = that.m_i;
			//调用基类的拷贝赋值函数，复制基
			//类子对象
			Base::operator=(that);//基类里没有拷贝赋值但是系统会为
			//它添加个
		}
	}
	int m_i;
};
int main(void)
{
	Derived d1(100,200);
	Derived d2(d1);
	cout << d1.Base::m_i <<' '<<d1.m_i << endl;
	cout << d2.Base::m_i <<' '<<d2.m_i << endl;
	Derived d3;
	d3 = d1;
	cout << d3.Base::m_i <<' '<<d3.m_i << endl;
	return 0;
}










