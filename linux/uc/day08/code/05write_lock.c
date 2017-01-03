//向文件b.txt中写入数据"hello"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开文件b.txt
	int fd = open("b.txt",O_WRONLY);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2.准备一把写锁
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 10;
	lock.l_pid = -1;
	//3.判断能否加锁成功
	int res = fcntl(fd,F_SETLK,&lock);
	if(-1 == res)
	{
		printf("文件已被加锁，无法执行写操作\n");
	}
	else
	{
		//2.向文件中写入字符串内容
		res = write(fd,"hello",6);
		if(-1 == res)
		{
			perror("write"),exit(-1);
		}
		printf("成功写入数据到文件中，写入的数据大小是：%d\n",res);
	}
	//4.关闭文件b.txt
	res = close(fd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}











