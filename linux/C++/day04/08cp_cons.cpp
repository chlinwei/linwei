#include <iostream>
using namespace std;

class A{
public:
	A(int data = 0){
		cout << "A::A(int)" << endl;
		m_data = data;
	}
	A(const A& that){//拷贝构造函数
		cout << "A::A(const A&)" << endl;
		m_data = that.m_data;
	}
	int m_data;
};
class B{
public:
	B(void){
		cout << "B::B(void)" << endl;
	}
	A m_a;
};
int main(void)
{
	B b;
	b.m_a.m_data = 200;
	B b2(b);//拷贝构造
	cout << b.m_a.m_data << endl;
	cout << b2.m_a.m_data << endl;
	return 0;
}




