/*单例模式：恶汉式*/
#include <iostream>
using namespace std;

class A{
public:
	static A& getInstance(void){//
		return s_instance;
	}
private:
	A(int data = 0):m_data(data){}//构造函数可以放在private和拷贝构造函数一样
	//但是放在私有里的话,实例化对象的时候会调用构造函数或拷贝构造函数
	//因为放在私有里面所以不能被调用
	A(A const& that);//拷贝构造函数
	int m_data;
	static A s_instance;//因为要是单例模式,所以构造函数(拷贝)都不能
	//放在共有里面,这样会创建很多对象的,构造函数只能放在私有里面,
	//因为是单例,即只有一个A类,必须是静态类,如果是成员类,则会报错
	//不管是共有还是私有,因为这个类位构造完整,而静态类是可以的,
	//这个静态类,
};
A A::s_instance(1234);

int main(void)
{
	A& a1 = A::getInstance();
	A& a2 = A::getInstance();
	cout << &a1 << ',' << &a2 << endl;
	cout << &a2 << ',' << &a2 << endl;

	return 0;
}
