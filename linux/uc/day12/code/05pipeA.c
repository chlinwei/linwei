//使用有名管道实现进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开管道文件
	int fd = open("a.pipe",O_WRONLY);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	//2.向管道文件中写入数据
	int i = 0;
	for(i = 1; i < 100; i++)
	{
		int res = write(fd,&i,sizeof(int));
		if(-1 == res)
		{
			perror("write"),exit(-1);
		}
	}
	//3.关闭文件
	int res = close(fd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	//练习：vi 05pipeB.c文件，读取管道文件中的内容
	return 0;
}











