//观察vfork和execl函数启动进程的处理方式
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
	//1.设置对信号2进行自定义处理
	signal(SIGINT,fa);
	//2.设置对信号3进行忽略处理
	signal(SIGQUIT,SIG_IGN);
	//3.使用vfork函数创建子进程，并跳转
	pid_t pid = vfork();
	if(-1 == pid)
	{
		perror("vfork"),exit(-1);
	}
	// 子进程
	if(0 == pid)
	{
		printf("子进程%d开始执行\n",getpid());
		execl("./proc","proc",NULL);
	}
	//4.父进程结束
	printf("父进程结束\n");
	return 0;
}










