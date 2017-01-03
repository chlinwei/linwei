//使用signal函数设置信号的处理方式
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
}

int main(void)
{
	//打印当前进程的进程号
	printf("pid = %d\n",getpid());
	//设置对信号2进行忽略处理
	if(SIG_ERR == signal(SIGINT,SIG_IGN))
	{
		perror("signal"),exit(-1);
	}
	//设置对信号3进行自定义处理
	if(SIG_ERR == signal(SIGQUIT,fa))
	{
		perror("signal"),exit(-1);
	}
	//进入无限循环，等待信号的到来
	while(1);
	return 0;
}










