//使用第二个函数指针设置信号的处理函数
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void fa(int signo,siginfo_t* info,void* p)
{
	printf("进程%d发来了信号%d\n",info->si_pid,signo);
}

int main(void)
{
	//准备结构体变量
	struct sigaction action = {};
	//初始化第二个函数指针
	action.sa_sigaction = fa;
	//处理标志设置为SA_SIGINFO
	action.sa_flags = SA_SIGINFO;

	//设置对信号2进行自定义处理
	sigaction(SIGINT,&action,NULL);
	printf("当前进程的进程号是:%d\n",getpid());
	while(1);
	return 0;
}









