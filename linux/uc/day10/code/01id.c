//各种ID的获取
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	printf("当前进程的进程号是：%d\n",getpid());
	printf("当前进程父进程的进程号是：%d\n",getppid());
	printf("当前进程对应的用户编号是：%d\n",getuid());
	printf("当前进程对应的用户组编号是：%d\n",getgid());
	return 0;
}






