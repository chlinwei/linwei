//使用dup函数复制文件描述符
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开/创建文件a.txt
	int fd = open("a.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开/创建文件成功,fd = %d\n",fd); // 3
	//2.复制文件描述符
	// int fd2 = fd; // error
	int fd2 = dup(fd);
	if(-1 == fd2)
	{
		perror("dup"),exit(-1);
	}
	// 3  4
	printf("fd = %d,fd2 = %d\n",fd,fd2);
	
	//分别使用3和4向文件中写入数据
	// 数据不会产生覆盖
	write(fd,"A",sizeof(char));//写入a.txt 
	write(fd2,"a",sizeof(char));//写入a.txt
	
	//3.关闭文件a.txt
	int res = close(fd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	//printf("成功关闭文件\n");
	res = close(fd2);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}
