//使用mmap函数建立文件到虚拟地址的映射
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

//定义员工的数据类型
typedef struct
{
	int id;
	char name[20];
	double salary;
}Emp;

int main(void)
{
	//1.打开文件emp.dat
	int fd = open("emp.dat",O_RDWR);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2.建立虚拟地址到文件的映射
	void* pv = mmap(NULL,3*sizeof(Emp),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(MAP_FAILED == pv)
	{
		perror("mmap"),exit(-1);
	}
	printf("建立映射成功\n");
	//3.通过虚拟地址打印文件内容
	Emp* pe = pv;
	int i = 0;
	for(i = 0; i < 3; i++)
	{
		printf("%d,%s,%lf\n",pe[i].id,pe[i].name,pe[i].salary);
	}
	//4.解除映射
	int res = munmap(pv,3*sizeof(Emp));
	if(-1 == res)
	{
		perror("munmap"),exit(-1);
	}
	printf("解除映射成功\n");
	//5.关闭文件emp.dat
	res = close(fd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}








