#include <iostream>
using namespace std;

class A{
public:
	A(int data){
		cout << "A::A(int)" << endl;
		m_data = data;
	}
	int m_data;
};
class B{
public:
	B(void):m_a(100){
		cout << "B::B(void)" << endl;
	}
	A m_a;
};
int main(void)
{
	B b;
	cout << b.m_a.m_data << endl;
	return 0;
}
