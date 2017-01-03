#include <iostream>
using namespace std;
class A{

	public:
	~A(void){
		cout << "A::~A()" << endl;
	}
};
int main(void){
	A a;//堆里的变量会在右花括号时调用析构函数
	A* p = &a;
	delete p; //编译通过,运行时出现段错误
	//原因:delete p时已经调用了a里的析构函数,在右花括号时,又再次析构
	//所以报错
	return 0;
}
