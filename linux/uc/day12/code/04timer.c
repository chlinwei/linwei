//计时器的启动和关闭
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <signal.h>

void fa(int signo)
{
	printf("贪吃蛇走了一步\n");
}

int main(void)
{
	//首先对信号SIGALRM进行自定义处理
	signal(SIGALRM,fa);
	//准备结构体变量
	struct itimerval timer;
	// 设置间隔时间为1.3秒
	timer.it_interval.tv_sec = 1;
	timer.it_interval.tv_usec = 300000;
	// 设置启动时间为5秒
	timer.it_value.tv_sec = 5;
	timer.it_value.tv_usec = 0;

	//使用setitimer函数来启动计时器
	int res = setitimer(ITIMER_REAL,&timer,NULL);
	if(-1 == res)
	{
		perror("setitimer"),exit(-1);
	}
	while(1);
	return 0;
}







