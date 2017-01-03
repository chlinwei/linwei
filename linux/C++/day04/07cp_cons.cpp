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
int main(void)
{
	A a1(100);
	//A a2(a1);
	A a2 = a1;//等价上面的写法
	cout << "a1::" << a1.m_data << endl;
	cout << "a2::" << a2.m_data << endl;
	return 0;
}




