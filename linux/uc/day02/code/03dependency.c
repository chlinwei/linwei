// #pragma GCC dependency 的使用
#include <stdio.h>

// 表示当前文件  依赖于   01line.c
#pragma GCC dependency "01line.c"
int main(void)
{
	printf("到底是否会产生警告信息呢？\n");
	return 0;
}
