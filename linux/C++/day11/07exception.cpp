#include <iostream>
using namespace std;

class A{
public:
	void func(void){
		throw -1;
	}
	~A(void){
		throw -2;
	}
};
int main(void)
{
	try{
		A a;
		a.func();
	}
	catch (int& ex){
		cout << "ex=" << ex <<endl;
		return -1;
	}
	return 0;
}



