//使用F_GETLK函数作为函数的实参
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
	//lock.l_type = F_RDLCK;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 2;
	lock.l_len = 12;
	lock.l_pid = -1;
	//3.使用fcntl函数尝试进行加锁
	int res = fcntl(fd,F_GETLK,&lock);
	if(-1 == res)
	{
		perror("fcntl"),exit(-1);
	}
	printf("F_RDLCK = %d,F_WRLCK = %d,F_UNLCK = %d\n",F_RDLCK,F_WRLCK,F_UNLCK);
	//4.打印参数锁信息
	printf("l_type = %d,l_whence = %d,l_start = %ld,l_len = %ld,l_pid = %d\n",lock.l_type,lock.l_whence,lock.l_start,lock.l_len,lock.l_pid);
	//5.关闭文件b.txt
	res = close(fd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}










