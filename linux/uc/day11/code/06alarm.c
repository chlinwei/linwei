//使用alarm函数发送信号
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
     //主要用于在经过参数指定的秒数之后发送SIGALRM信号给当前正在调用的进程
//每次设置新闹钟之后会取消之前的闹钟，参数为0时不会设置新闹钟，专门用于取消闹钟

    //成功返回之前闹钟剩余的秒数，如果之前没有闹钟则返回0
void fa(int signo)
{
	printf("捕获到了信号%d\n",signo);
	alarm(1);
}

int main(void)
{
	//设置对SIGALRM信号进行自定义处理
	signal(SIGALRM,fa);
	//5秒后发送信号SIGALRM
	int res = alarm(5);
	printf("res = %d\n",res); // 0

	sleep(2);
	// 调整闹钟为10秒后触发
	res = alarm(10);
	printf("res = %d\n",res); // 3

	// 取消闹钟
	//res = alarm(0);
	//printf("res = %d\n",res); // 10
	while(1);
	return 0;
}









