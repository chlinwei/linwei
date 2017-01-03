//使用vfork函数创建子进程
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	//1.使用vfork函数创建子进程
	pid_t pid = vfork();
	if(-1 == pid)
	{
		perror("vfork"),exit(-1);
	}
	//2.子进程开始执行
	if(0 == pid)
	{
		printf("子进程%d开始执行...\n",getpid());
		sleep(10);
		printf("子进程结束\n");
		_exit(0);
		//exit(0);  error
	}
	//3.父进程开始执行
	else
	{
		printf("父进程开始执行...\n");
		printf("父进程结束\n");
	}
	return 0;
}










