//继承,基类的构造函数,和析构函数无法被之类继承
#include <iostream>
using namespace std;
/*
class A{
	public:
		int m_a;
};

class B:public A{
	public:
		B(int b):m_b(b){}
		int m_b;
};
解析:B继承A,如果B中没有调用A的构造函数(拷贝),则系统会
在B中调用A的无参构造函数,因为A中没有写构造函数,系统也会为
A中添加个无参构造函数,B中调用的A的无参构造函数,恰好A中
有(系统添加的),所以不会报错
*/
/*
class A{
	public:
		A(int a):m_a(a){}
		int m_a;
}
class B:public {
	public:
		B(int b):m_b(b){}
		int m_b;
};*/
//解析:B继承A,B类中,没有调用A的构造函数,则系统会自动在
//B的构造函数的初始化列表中,调用A的无参构造函数(你没写,系统提供的),
//但是A类中,本身有个有参构造函数,所以没有无参构造函数,则会报错
class A{
	public:
		A(int a):m_a(a){}
		A(void){
			cout << "A::A(void),A构造函数" << endl;
		}
	private:
		int m_a;
};
class B:public A{
	public:
		B(int b):m_b(b){
			cout << "B::B(int)" << endl;
		}
		B(){
			cout << "B::B()" << endl;
		}
		int m_b;
};
//解析:B继承A,在B的初始化列表中就一定会调用A的构造函数
//但是B的初始化列表中没调用A的构造函数,则系统会自动添加个
//A的无参构造函数,A类中正好有个无参构造函数,所以不会报错
int main(void){
	B b(100);
	//B c;如果B中没写B(){}构造函数的话,就报错,因为这种B c;写法就
	//是来调用B(){}无参构造函数的,没写就会报错
	B c();//调用的是B::B(int)类型的(有参)
	B d;//调用的是B::B()类型的(无参)
	return 0;
}

