#include <iostream>
class A{
	public:
		A(){
			std::cout << "A::A()" << std::endl;
		}
		~A(){
			std::cout << "A::~A()" << std::endl;
		}
};

class B{
	public:
		B(){
			std::cout << "B::B()" << std::endl;
		}
		~B(){
			std::cout << "B::~B()" << std::endl;
		}
};

class C{
	public:
		C(){
			std::cout << "C::C()" << std::endl;
		}
		~C(){
			std::cout << "C::~C()" << std::endl;
		}
};

void func(void){
	throw C();//调用C的构造函数,直接跳转到'}'
}
int main(void){

	try{
		func();//直接跳转到'}'
	}
	catch(int& ex){//这里发现int& ex = 匿名对象,不成立,则直接倒转到转到'}'
		std::cout << "catch:int" << std::endl;//不执行
	}
	catch(B& ex){//B& ex =匿名对象,不成立,直接跳转到'}'
		std::cout << "catch:B" << std::endl;//不执行
	}
	catch(C& ex){//C& ex = 匿名对象,成立,则执行catch体内的语句
		std::cout << "catch:C" << std::endl;//执行
	}//这里调用匿名对象的析构函数
	return 0;
}
