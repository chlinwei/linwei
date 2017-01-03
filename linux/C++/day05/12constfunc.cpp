#include <iostream>
using namespace std;

class A{
public:
	void func(void)const{
		cout << "func常版本" << endl;
	}
	void func(void){
		cout << "func非常版本" << endl;
	}
};
int main(void)
{
	//非常对象会优先选择非常版本,
	//常对象只能选择常版本
	A a;
	a.func();//func(&a)
	const A& r = a;
	r.func();
	return 0;
}



