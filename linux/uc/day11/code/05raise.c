//使用raise函数发送信号
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
    // 主要用于给当前正在调用的进程/线程发送参数指定的信号，对于单线程的进程来说，等价于kill(getpid(),sig)

void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
}

int main(void)
{
	printf("pid = %d\n",getpid());
	//设置对信号SIGINT进行自定义处理
	signal(SIGINT,fa);
	// 10秒后发送信号SIGINT/SIGQUIT
	int res = sleep(10);
	if(0 == res)
	{
		printf("美美地睡了一觉\n");
	}
	else
	{
		printf("睡眠被打断，睡了%d秒\n",10 - res);
	}
	// 使用raise函数发送信号
	//res = raise(SIGINT);
	res = raise(SIGQUIT);
	if(0 != res)
	{
		perror("raise"),exit(-1);
	}
	return 0;
}








