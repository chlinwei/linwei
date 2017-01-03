#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	printf("当前进程的进程号是：%d\n",getpid());
	int* p1 = (int*)malloc(4096);
	printf("申请了1个内存页大小的空间\n");
	getchar(); // scanf("%c",&c);

	int* p2 = (int*)malloc(30*4096);
	printf("申请了30个内存页大小的空间\n");
	getchar();

	int* p3 = (int*)malloc(3*4096);
	printf("申请了3个内存页大小的空间\n");
	getchar();

	free(p3);
	printf("释放了3个内存页大小的空间\n");
	getchar();

	free(p2);
	printf("释放了30个内存页大小的空间\n");
	getchar();

	free(p1);
	printf("释放了1个内存页大小的空间，此时全部动态内存释放完毕\n");
	getchar();

	return 0;
}








