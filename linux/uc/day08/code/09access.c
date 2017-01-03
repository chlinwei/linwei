//函数access的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	//判断文件是否存在
	if(0 == access("a.txt",F_OK))
	{
		printf("文件存在\n");
	}
	//判断文件是否可读
	if(0 == access("a.txt",R_OK))
	{
		printf("文件可读\n");
	}
	//判断文件是否可写
	if(0 == access("a.txt",W_OK))
	{
		printf("文件可写\n");
	}
	//判断文件是否可执行
	if(0 == access("a.txt",X_OK))
	{
		printf("文件可执行\n");
	}
	return 0;
}






