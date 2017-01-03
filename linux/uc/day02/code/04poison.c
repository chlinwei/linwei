// #pragma GCC poison 的使用
#include <stdio.h>

//采用宏定义进行瞒天过海
#define GOTO goto
//设置goto为毒药
#pragma GCC poison goto
//#pragma GCC poison int

int main(void)
{
	loop:
		printf("我是帅哥我怕谁\n");
	GOTO loop;
	return 0;
}



