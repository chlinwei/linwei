//使用kill函数发送信号
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
}

int main(void)
{
	//1.使用fork函数创建子进程
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	//2.子进程开始执行，对50进行自定义处理
	if(0 == pid)
	{
		printf("子进程%d开始执行\n",getpid());
		signal(50,fa);
		while(1);
	}
	//3.父进程判断子进程是否存在，并发信号
	sleep(1);
	if(0 == kill(pid,0))
	{
		printf("父进程开始发送信号50\n");
		kill(pid,50);
	}
	return 0;
}










