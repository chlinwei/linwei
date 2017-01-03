#include <iostream>
#include <stdio.h> //C风格
#include <cstdio>  //C++风格

int main(void)
{
	std::cout << "hello world" << std::endl;
	printf("hello world\n");
	int a;
	std::cin >> a;//从键盘读一个整形数放到a中
	std::cout << a << std::endl;//输出a
	return 0;
}
