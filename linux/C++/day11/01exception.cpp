#include <iostream>
#include <cstdio>
using namespace std;

class A{
public:
	A(void){cout << "A::A()" << endl;}
	~A(void){cout << "A::~A()" << endl;}
};
int func3(void){
	A a;
	FILE *fp = fopen("none.txt","r");
	if(!fp){
		throw -1;//跳转到当前作用域"}"
	}
	//...
	fclose(fp);
	return 0;
}
int func2(void){
	A a;
	func3();
	//...
	return 0;
}
int func1(void){
	A a;
	func2();
	//...
	return 0;
}
int main(void)
{
	try{
		func1();
		//...
	}
	catch(int ex){
		cout << "ex=" << ex << endl;
		cout << "file open error" << endl;
		return -1;
	}
	return 0;
}



















