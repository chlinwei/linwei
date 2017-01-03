//虚继承
#include <iostream>
using namespace std;
/*
class A{
	public:
		int a;
};
class B:public A{
};
class C:public A{
};
class D:public B,public C{
};
int main(void){
	D d;
	return 0;
}
*/

//上述代码不会报错
//但是一旦使用,d.a = 1;就会报个对a的返回不明确的错误
//原因是d保存了两份A的副本,即有两个成员变量a,虚继承就可以解决这个问题
