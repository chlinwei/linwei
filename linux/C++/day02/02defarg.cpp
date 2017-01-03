#include <iostream>
using namespace std;

void foo(int a,int b=200,int c=300);
/*注意调用时歧义错误*/
//void foo(int a){}
int main(void)
{
	foo(10,20,30);
	foo(10,20);
	foo(10);
}
void foo(int a,int b/*=200*/,int c/*=300*/)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}



