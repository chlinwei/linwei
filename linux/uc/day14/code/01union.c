//小端系统和大端系统的概念
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//定义联合的数据类型
	union Un
	{
		int x;
		char buf[4];
	};
	union Un un;
	un.x = 0x12345678;
	int i = 0;
	for(i = 0; i < 4; i++)
	{
		printf("buf[%d] = %#x[%p]\n",i,un.buf[i],&un.buf[i]);
	}
	return 0;
}







