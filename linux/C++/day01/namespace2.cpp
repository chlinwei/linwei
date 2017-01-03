#include <iostream>
//名字空间指令，以后使用std中成员可以
//省略std::
using namespace std;
namespace ns1{
	void func(void){
		cout << "ns1::func()" << endl;
	}
}
namespace ns2{
	void func(void){
		cout << "ns2::func()" << endl;
	}
};
int main(void)
{
	using namespace ns1;
	func();
	using namespace ns2;//引入歧义错误
	//func();
	return 0;
}



