//使用umask函数设置文件创建时的权限屏蔽字
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	//当前系统环境默认屏蔽权限 002
	mode_t old = umask(0055);
	printf("old = %o\n",old); // 2

	//1.创建文件b.txt
	int fd = open("b.txt",O_RDWR|O_CREAT|O_EXCL,0777);
	if(-1 == fd)
	{
		perror("open"),exit(-1);
	}
	printf("创建文件成功\n");
	// 恢复系统默认的权限屏蔽字
	umask(old);
	//2.关闭文件b.txt
	int res = close(fd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("成功关闭文件\n");
	return 0;
}









