//使用wait函数等待子进程结束
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	//1.使用fork函数创建子进程
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	//2.子进程开始执行
	if(0 == pid)
	{
		printf("子进程%d开始执行...\n",getpid());
		sleep(10);
		printf("子进程结束\n");
		exit(100);
	}
	//3.父进程等待子进程结束，打印相关信息
	printf("父进程开始等待...\n");
	int status = 0;
	int res = wait(&status);
	if(-1 == res)
	{
		perror("wait"),exit(-1);
	}
	if(WIFEXITED(status))
	{
		printf("子进程%d已终止，终止时的退出状态信息是：%d\n",res,WEXITSTATUS(status));
	}
	return 0;
}





