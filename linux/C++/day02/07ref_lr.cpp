#include <iostream>
using namespace std;

int foo(void){
	int a  = 100;
	cout << "&a=" << &a << endl;
	return a;
}
int main(void)
{
	const int& r = foo();
	//r对应临时变量的地址
	cout << "&r=" << &r << endl;
	cout << "r=" << r << endl;//100
	int a=10,b=20;
	const int& c = a+b;//a+b返回右值

	char ch = 'A';
	//char->int隐士转换，结果是右值
	int& i = ch;
	return 0;
}






