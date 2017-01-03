//使用有名管道实现进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开文件
	int fd = open("a.pipe",O_RDONLY);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	//2.读取文件中的数据
	int i = 0;
	for(i = 1; i < 100; i++)
	{
		int x = 0;
		int res = read(fd,&x,sizeof(int));
		if(-1 == res)
		{
			perror("read"),exit(-1);
		}
		printf("%d ",x);
	}
	printf("\n");
	//3.关闭文件
	int res = close(fd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	return 0;
}









