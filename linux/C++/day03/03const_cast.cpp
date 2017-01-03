#include <iostream>
using namespace std;

int main(void)
{
	/*volatile修饰的变量表示是易变，这样
	 要求编译器每次使用该变量时都要从内存
	 中读取，而不是取寄存器中的备份，防止
	 编译器优化*/
	const volatile int ci = 100;
	int* pci = const_cast<int*>(&ci);
	*pci = 200;
	cout << "ci=" << ci << endl;
	cout << "&ci=" << (void*)&ci << endl;
	cout << "*pci=" << *pci << endl;
	cout << "pci=" << pci << endl;
	return 0;
}
