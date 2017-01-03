#include <iostream>
using namespace std;

class A{
public:
	void func1(void)const{
		cout << "常函数" << endl;
	}
	void func2(void){
		cout << "非常函数" << endl;
	}
};
int main(void)
{
	A a;//非常对象
	a.func1();
	a.func2();
//常对象只能调用常函数
//非常对象既可以调用非常函数也可以调用普通函数
	const A a2 = a;//常对象
	a2.func1();
	//a2.func2();
	const A* p = &a;//常指针
	p->func1();
	//p->func2();
	const A& r = a;//常引用
	r.func1();
	//r.func2();

	return 0;
}



