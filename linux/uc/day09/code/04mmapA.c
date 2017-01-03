//使用mmap函数建立文件到虚拟内存地址的映射
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

//定义员工的数据类型
typedef struct
{
	int id;//员工编号
	char name[20];//员工姓名
	double salary;//员工薪水
}Emp;

int main(void)
{
	//1.创建/打开文件emp.dat
	int fd = open("emp.dat",O_RDWR|O_CREAT|O_TRUNC,0664);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开/创建文件成功\n");
	//2.调整文件大小,保证可存放3个员工信息
	int res = ftruncate(fd,3*sizeof(Emp));
	if(-1 == res)
	{
		perror("ftruncate"),exit(-1);
	}
	printf("调整文件的大小成功\n");
	//3.建立文件到虚拟地址之间的映射
	void* pv = mmap(NULL,3*sizeof(Emp),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(MAP_FAILED == pv)
	{
		perror("mmap"),exit(-1);
	}
	printf("建立文件到虚拟地址的映射成功\n");
	//4.通过虚拟地址存放员工信息
	Emp* pe = pv;
	pe[0].id = 1001;
	strcpy(pe[0].name,"zhangfei");
	pe[0].salary = 3000;

	pe[1].id = 1002;
	strcpy(pe[1].name,"guanyu");
	pe[1].salary = 3500;

	pe[2].id = 1003;
	strcpy(pe[2].name,"liubei");
	pe[2].salary = 4000;

	//5.解除文件到虚拟地址的映射
	res = munmap(pv,3*sizeof(Emp));
	if(-1 == res)
	{
		perror("munmap"),exit(-1);
	}
	printf("解除映射成功\n");
	//6.关闭文件emp.dat
	res = close(fd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	//练习：vi 04mmapB.c文件，使用映射的机制来打印文件中的员工信息
	return 0;
}








