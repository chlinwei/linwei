#include <iostream>
using namespace std;

class A{
public:
	A(void){
		cout << "A::A(void)" << endl;
	}
	A(const A& that){
		cout << "A::A(const A&)" << endl;
	}
};
void func(A a){}

//-fno-elide-constructors,不让编译优化处理
A bar(void){
	A a;
	cout << "bar::" << &a << endl;
	return a;//从函数中返回对象
}
int main(void)
{
	A a;
	func(a);
	A a2 = bar();
	cout << "main::" << &a2 << endl;
	return 0;
}







