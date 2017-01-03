//使用sbrk函数和brk函数搭配使用
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	int* pi = (int*)sbrk(sizeof(int));
	if((int*)-1 == pi)
	{
		perror("sbrk"),exit(-1);
	}
	*pi = 66;
	
	double* pd = (double*)sbrk(sizeof(double));
	if((double*)-1 == pd)
	{
		perror("sbrk"),exit(-1);
	}
	*pd = 3.14;

	char* pc = (char*)sbrk(sizeof(char)*10);
	if((char*)-1 == pc)
	{
		perror("sbrk"),exit(-1);
	}
	strcpy(pc,"hello");

	printf("*pi = %d,*pd = %lf,pc = %s\n",*pi,*pd,pc);
	//释放所有的内存空间
	int res = brk(pi);
	if(-1 == res)
	{
		perror("brk"),exit(-1);
	}
	printf("所有内存空间释放完毕\n");
	return 0;
}







