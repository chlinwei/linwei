//使用system函数执行shell命令
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	//调用system函数执行shell命令
	system("ls -l");
	return 0;
}









