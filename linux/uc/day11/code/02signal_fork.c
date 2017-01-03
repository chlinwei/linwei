//观察父子进程对信号的处理方式
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//fork
#include <signal.h>//signal
#include <sys/types.h>//getpid：unistd.h sys/types.h
 

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
}

int main(void)
{
	//打印进程号
	printf("当前进程的进程号是：%d\n",getpid());
	//设置对信号2进行自定义处理
	if(SIG_ERR == signal(SIGINT,fa))
	{
		perror("signal"),exit(-1);
	}
	//设置对信号3进行忽略处理
	if(SIG_ERR == signal(SIGQUIT,SIG_IGN))
	{
		perror("signal"),exit(-1);
	}
	//使用fork函数创建子进程
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	// 子进程
	if(0 == pid)
	{
		printf("子进程%d开始执行\n",getpid());
		while(1);
	}
	printf("父进程结束\n");
	return 0;
}






