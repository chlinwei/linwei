//使用sigaction函数来设置信号的处理方式
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void fa(int signo)
{
	printf("开始处理信号...\n");
	sleep(10);
	printf("处理信号完毕\n");
}

int main(void)
{
	//准备结构体变量
	struct sigaction action = {};
	
	//设置信号的自定义处理函数
	action.sa_handler = fa;

	//设置执行信号处理函数期间屏蔽的信号
	sigemptyset(&action.sa_mask);
	//屏蔽信号3
	sigaddset(&action.sa_mask,3);
	
	//设置处理的标志位
	// 解除对信号2的屏蔽
	//action.sa_flags = SA_NODEFER;
	// 自定义处理一次，下次默认处理
	// 默认屏蔽与触发信号处理函数相同的信号
	action.sa_flags = SA_RESETHAND;

	//使用sigaction函数对信号2自定义处理
	sigaction(SIGINT,&action,NULL);
	printf("当前进程的进程号是：%d\n",getpid());
	while(1);
	return 0;
}










