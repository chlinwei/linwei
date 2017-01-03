//使用fcntl函数实现解锁
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
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 10;
	lock.l_pid = -1;
	//3.使用fcntl函数进行加锁
	int res = fcntl(fd,F_SETLK,&lock);
	if(-1 == res)
	{
		perror("fcntl"),exit(-1);
	}
	printf("加锁成功，开始使用文件...\n");
	//4.模拟占用20秒之后进行解锁
	sleep(20);
	//printf("使用文件结束，开始解锁...\n");
	printf("使用文件结束，开始关闭文件...\n");
	//5.解锁之后占用20秒
	/*
	lock.l_type = F_UNLCK;
	res = fcntl(fd,F_SETLK,&lock);
	if(-1 == res)
	{
		perror("fcntl"),exit(-1);
	}
	printf("解锁成功，20秒后关闭文件...\n");
	sleep(20);
	*/
	//6.关闭文件b.txt
	res = close(fd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("成功关闭文件,20秒后进程结束\n");
	sleep(20);
	printf("进程结束\n");
	return 0;
}









