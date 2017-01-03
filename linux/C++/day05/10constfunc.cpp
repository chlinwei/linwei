#include <iostream>
using namespace std;

class A{
public:
	A(int data = 0):m_data(data){}
	void show(void)const{
		cout << m_data++ << endl;
		//cout <<const_cast<A*>(this)->m_data++
		   	//<< endl;
	}
	/*void show(const A* this)*/
private:
	/*mutable修饰的变量可以在常函数中被修改*/
	mutable int m_data;
};
int main(void)
{
	A a(123);
	a.show();
	a.show();
	return 0;
}

