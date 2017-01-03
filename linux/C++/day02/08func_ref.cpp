#include <iostream>
using namespace std;

void swap1(int x,int y){
	x = x ^ y;//011 ^ 101 = 110
	y = x ^ y;//110 ^ 101 = 011 y=3
	x = x ^ y;//110 ^ 011 = 101 x=5
}
void swap2(int* x,int* y){
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}
void swap3(int& x,int& y){
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
}
int main(void)
{
	int a = 3,b = 5;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	//swap1(a,b);
	//swap2(&a,&b);
	swap3(a,b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	/*作业，实现一个swap4函数，实现两个字
	  符串的交换，要求使用引用型的参数*/
	const char* s1 = "hello";
	const char* s2 = "world";
	//swap4(s1,s2);
	cout << "s1=" << s1 << endl;//world
	cout << "s2=" << s2 << endl;//hello
	return 0;
}



