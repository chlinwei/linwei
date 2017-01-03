//使用各种函数来终止进程
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void show(void)
{
	printf("调用我可以进行善后处理哟!\n");
}

int main(void)
{
	//使用atexit函数注册一个函数show
	int res = atexit(show);
	if(0 != res)
	{
		perror("atexit"),exit(-1);
	}	
	printf("main函数开始执行\n");
	//调用终止进程的功能函数
	//_exit(0);
	//_Exit(0);
	exit(0);
	printf("main函数结束\n");
	return 0;
}











