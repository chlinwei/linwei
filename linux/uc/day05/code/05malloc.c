//使用malloc申请动态内存的一般性原则
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	printf("当前进程的进程号是：%d\n",getpid());
	// 16进制的21000 转换结果为33个内存页
	// 16进制的1000 转换结果为 1个内存页
	int* pi = (int*)malloc(sizeof(int));
	printf("pi = %p\n",pi);
	
	//故意越界一下试试，不超过33个内存页时，是否会引起段错误
	//*(pi+10000) = 250;
	//printf("*(pi+10000) = %d\n",*(pi+10000)); // 250

	// 故意越界超过33个内存页的范围
	*(pi+1024*33) = 250;
	printf("*(pi+1024*33) = %d\n",*(pi+1024*33)); // 段错误
	while(1);
	return 0;
}









