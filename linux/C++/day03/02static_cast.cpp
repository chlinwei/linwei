#include <iostream>
using namespace std;

int main(void)
{
	int* pi = NULL;
	//char c = (int)pi;//C风格
	char c = int(pi);//C++风格

	void* pv = pi;//隐士转换
	pi = static_cast<int*>(pv);//静态转换
	//c = static_cast<int>(pi);//无法静态
	return 0;
}
