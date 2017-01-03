//使用fcntl函数对文件进行加锁操作
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	printf("当前进程的进程号是：%d\n",getpid());
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
	//3.使用fcntl函数对文件加锁
	int res = fcntl(fd,F_SETLK,&lock);
	if(-1 == res)
	{
		perror("fcntl"),exit(-1);
	}
	printf("加锁成功，开始使用文件...\n");
	//4.占用20秒模拟使用文件的效果
	sleep(20);
	printf("使用文件结束，即将关闭文件\n");
	//5.关闭文件
	res = close(fd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	//练习：vi 03lockB.c文件，要求给文件b.txt中前10个字节加写锁，判断加锁是否成功即可
	return 0;
}










