//使用fcntl函数对文件进行加锁
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//1.打开文件b.txt
	int fd = open("b.txt",O_RDWR);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("打开文件成功\n");
	//2.准备一把锁
	struct flock lock;
	lock.l_type = F_RDLCK;
	//lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 10;
	lock.l_pid = -1;
	//3.使用fcntl函数进行加锁，判断是否成功
	int res = fcntl(fd,F_SETLK,&lock);
	if(-1 == res)
	{
		printf("加锁失败\n");
	}
	else
	{
		printf("加锁成功\n");
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










