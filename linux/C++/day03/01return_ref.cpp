#include <iostream>
using namespace std;

struct A{
	int data;
	const int& foo(void){
		return data;
	}
	//返回局部变量引用危险!
	int& bar(void){
		int data = 1000;
		cout << "bar::" << &data << endl;
		return data;
	}
	int& hum(void){
		int data = 2000;
		cout << "hum::" << &data << endl;
		return data;
	}
};
int main(void)
{
	A a={0};
	//a.foo() = 100;
	cout << a.data << endl;//100

	int& data = a.bar();
	cout << "main::" << &data << endl;

	cout << data << endl;//1000
	a.hum();
	cout << data << endl;//2000

	return 0;
}





