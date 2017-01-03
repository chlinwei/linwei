//虚函数(只有类的成员函数才能被申明为虚函数,类的静态成员函数不能被申明为虚函数)
//成员函数前面加上virtual即申明为虚函数
//虚函数条件,在子类函数中,要想覆盖基类的函数的版本,
//(1),如果返回类型不是子类类型的指针或者引用,则
//函数签名(函数名,形参列表,常属性一样),返回类型要一样
//(2),如果返回类型是子类类型的指针或者引用,则只需要
//函数签名一样就OK了
#include <iostream>
using namespace std;
class A{
	public:
	void func(void){
		cout << "A::func()" << endl;
	}
	virtual void v_func(){
		cout << "A::v_fun()" << endl;
	}
};
class B:public A{
	public:
		void func(void){
			cout << "B::func()" << endl;
		}
		virtual void v_func(void){//加virtual形成覆盖
			cout << "B::v_func()" << endl;
		}
};
int main(void){
	A* a= new B();//向上构造,多态的必要条件
	a->func();//调用的是基类中的函数,普通函数,在编译的时候就确定了调用
	//这个函数
	a->v_func();//调用的是之类中的函数,这是一个virtual函数,
	//在运行的时候通过某种机制来确定调用的函数
	return 0;
}
