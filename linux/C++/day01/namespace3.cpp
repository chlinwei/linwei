#include <iostream>
using namespace std;
namespace ns1{
	int num = 10;
	void func(void){
		cout << "ns1::func()" << endl;
	}
}
namespace ns2{
	void func(void){
		cout << "ns2::func()" << endl;
	}
}
int num = 20;
int main(void)
{
	using ns1::func;//名字空间声明
	func();
	using namespace ns2;//指令
	func();//局部隐藏外部
	ns2::func();
	using ns1::num;
	cout << num << endl;
	cout << ::num << endl;//20
	return 0;
}



