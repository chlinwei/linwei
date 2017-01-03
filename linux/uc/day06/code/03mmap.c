// 使用mmap函数建立虚拟地址到真实内存的映射
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main(void)
{
	//1.建立映射，使用mmap函数
	void* pv = mmap(
		NULL,//映射起始地址,由内核指定
		4,//映射的大小
		PROT_READ|PROT_WRITE,//可读可写
		MAP_PRIVATE|MAP_ANONYMOUS,//私有的
		0,//文件描述符
		0 //文件中的偏移量
	);
	if(MAP_FAILED == pv)
	{
		perror("mmap"),exit(-1);
	}
	printf("建立映射成功\n");
	//2.使用映射得到的地址
	//*pv = 66; error
	int* pi = pv;
	*pi = 66;
	printf("*pi = %d\n",*pi); // 66
	//3.解除映射，使用munmap函数
	int res = munmap(pv,4);
	if(-1 == res)
	{
		perror("munmap"),exit(-1);
	}
	printf("解除映射成功\n");
	return 0;
}










