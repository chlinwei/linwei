#include <iostream>

class A{
	public:
		A(void){
			std::cout << "A::A()" << std::endl;
		}
		~A(void){
			std::cout << "A::~A()" <<std::endl;
		}
};

class B:public A{
	public:
		B(void){
			std::cout << "B::B(void)"<<std::endl;
		}
		~B(void){
			std::cout << "B::~B(void)" << std::endl;
		}
};
void func(void){
	throw A(); //这里抛出一个匿名A类对象.
	//这里调用A的构造函数,直接跳转到},跳转到"}",但是不执行匿名的析构函数
	std::cout << "func()" << std::endl; //这里不执行
}
int main(void){
	try { //这里try 和catch都是一个局部作用域,和函数一样
		func();//直接跳转到'}',但是从func函数里,抛出的异常对象的析构函数
			   //还是不调用	
		std::cout << "try" << std::endl; //不执行
	}
	catch(A& ex){ 
		std::cout << "catch A"<<std::endl;
		return -1;
	}//这里执行匿名对象的析构函数
	std::cout << "main endl..." <<std::endl;
	return 0;
}
