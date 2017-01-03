#include <iostream>
using namespace std;
class A{
	public:
		A(int a):m_a(a){}
	private:
		int m_a;
};
class B:public A{
	public:
		B(int b):m_b(b),A(3){}
	private:
		int m_b;
};
int main(void){

	return 0;
}
