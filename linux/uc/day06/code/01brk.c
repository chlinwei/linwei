//使用brk函数调整动态内存的大小
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	//使用sbrk函数获取起始位置
	void* pv = sbrk(0);
	if((void*)-1 == pv)
	{
		perror("sbrk"),exit(-1);
	}
	printf("pv = %p\n",pv);
	//使用brk函数申请4个字节的内存空间
	int res = brk(pv+4);
	if(-1 == res)
	{
		perror("brk"),exit(-1);
	}
	printf("申请内存空间成功\n");
	//获取当前内存空间的末尾地址
	void* cur = sbrk(0);
	if((void*)-1 == cur)
	{
		perror("sbrk"),exit(-1);
	}
	printf("cur = %p\n",cur);

	//再次申请 4个字节的内存空间
	res = brk(pv+8);
	if(-1 == res)
	{
		perror("brk"),exit(-1);
	}
	//调用sbrk(0)获取当前位置
	cur = sbrk(0);
	if((void*)-1 == cur)
	{
		perror("sbrk"),exit(-1);
	}
	printf("cur = %p\n",cur); // pv + 8

	//释放所有的内存空间
	res = brk(pv);
	if(-1 == res)
	{
		perror("brk"),exit(-1);
	}
	cur = sbrk(0);
	if((void*)-1 == cur)
	{
		perror("sbrk"),exit(-1);
	}
	printf("cur = %p\n",cur); // pv
	return 0;
}





