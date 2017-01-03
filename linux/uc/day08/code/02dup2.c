//使用dup2函数来复制文件描述符
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.创建/清空文件a.txt
	int fd = open("a.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("创建/清空文件成功，fd = %d\n",fd); // 3
	//2.创建/清空文件b.txt
	int fd2 = open("b.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
	if(-1 == fd2)
	{
		perror("open"),exit(-1);
	}
	printf("创建/清空文件b.txt成功,fd2 = %d\n",fd2); // 4
	//3.使用dup2函数复制文件描述符
	int fd3 = dup2(fd,fd2);
	if(-1 == fd3)
	{
		perror("dup2"),exit(-1);
	}
	// 4  4 
	printf("fd2 = %d,fd3 = %d\n",fd2,fd3);
	//使用fd fd2 fd3分别写入数据
	write(fd,"A",1);// 写入a.txt
	write(fd2,"a",1);// 写入a.txt
	write(fd3,"1",1);// 写入a.txt

	//4.关闭文件a.txt和b.txt
	int res = close(fd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	res = close(fd2);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}










