#include <iostream>
using namespace std;

int num = 100;
class A{
public:
	/*A(void){
		m_r = num;
		m_c = 200; //注意初始化和复制的区别
	}*/
	A(void):m_r(num),m_c(200){}
	int& m_r;
	const int m_c;
};
int main(void)
{
	A a;
	cout << a.m_r << ' ' << a.m_c << endl;
	return 0;
}
