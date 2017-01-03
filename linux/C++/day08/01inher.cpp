#include <iostream>
using namespace std;

class A{
public:
	void foo(void){
		cout << "A::foo(void)" << endl;
	}
};

class B:public A{
public:
	void foo(int i){
		cout << "B::foo(int)" << endl;
	}
	void bar(void){
		/*A::*/foo();//这里如果不显示的指明foo(),来自A则会报错
		//因为B中只有void foo(int)类型的而不是void foo(void)类型的
		//foo(100);
	}
	using A::foo;
};
int main(void)
{
	B b;
	b.bar();
	return 0;
}




