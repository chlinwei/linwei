//使用fork函数创建子进程
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	printf("main函数开始执行\n");
	//调用fork函数创建子进程
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	//printf("main函数结束%d\n",pid);
	// 子进程
	if(0 == pid)
	{
		printf("我是子进程，我的进程号是：%d,我的父进程进程号是：%d\n",getpid(),getppid());
		sleep(3);
		printf("我是子进程，我的进程号是：%d,我的父进程进程号是：%d\n",getpid(),getppid());
	}
	// 父进程
	else
	{
		sleep(1);
		printf("我是父进程，我的进程号是：%d,我的子进程进程号是：%d\n",getpid(),pid);
	}
	return 0;
}












