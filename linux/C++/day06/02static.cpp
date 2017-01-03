#include <iostream>
using namespace std;

class A{
public:
	static void func(void){//静态成员函数和成员变量访问的途径有两个
		//作用域和对象
		//静态成员函数不能访问类的成员变量
		cout << "静态成员函数" << endl;
		cout << s_data << endl;
		//cout << m_data << endl;
	}
	void func2(void){
		cout << "非静态成员函数" << endl;
		cout << s_data << endl;
		cout << m_data << endl;
	}
	static int s_data;
	int m_data;
};
int A::s_data = 100;
int main(void)
{
	A a;
	a.m_data = 200;
	A::func();
	a.func2();
	return 0;
}
