#include <iostream>
using namespace std;

class A{
public:
	int m_data;
private:
	//static int s_data;
};
int A::s_data = 10;//定义及初始化
int main(void)
{
	A a;
	cout << sizeof(a) << endl;//4
	cout << A::s_data << endl;//10
	cout << a.s_data << endl;//10
	A a2;
	a2.s_data = 20;
	cout << a.s_data << endl; //20	
	return 0;
}










