//使用信号的屏蔽
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void fa(int signo)
{
	//printf("捕获到了信号%d\n",signo);
}

int main(void)
{
	//1.打印当前进程的进程号
	printf("当前进程的进程号是：%d\n",getpid());
	//2.设置对信号2,3以及50进行自定义处理
	signal(2,fa);
	signal(3,fa);
	signal(50,fa);
	//3.睡眠20秒
	int res = sleep(20);
	if(0 == res)
	{
		printf("美美地睡了一觉\n");
	}
	else
	{
		printf("没有信号屏蔽，睡眠被打断，睡了%d秒\n",20-res);
	}
	printf("------------------------\n");
	printf("开始信号的屏蔽...\n");
	//准备信号集类型的变量
	sigset_t set,old;
	//清空信号集
	sigemptyset(&set);
	sigemptyset(&old);
	//将信号2 3 50放置到信号集set中
	sigaddset(&set,2);
	sigaddset(&set,3);
	sigaddset(&set,50);
	// 设置屏蔽的信号集
	res = sigprocmask(SIG_SETMASK,&set,&old);
	if(-1 == res)
	{
		perror("sigprocmask"),exit(-1);
	}
	printf("设置信号屏蔽成功，old = %d\n",old);
	res = sleep(20);
	if(0 == res)
	{
		printf("有信号屏蔽就是任性，信号2、3、50来了也不理\n");
	}
	//使用sigpending函数获取来过的信号
	sigset_t pend;
	sigemptyset(&pend);
	res = sigpending(&pend);
	if(-1 == res)
	{
		perror("sigpending"),exit(-1);
	}
	//判断信号2 3 50是否来过
	if(sigismember(&pend,2) > 0)
	{
		printf("信号2来过\n");
	}
	if(sigismember(&pend,3) > 0)
	{
		printf("信号3来过\n");
	}
	if(sigismember(&pend,50) > 0)
	{
		printf("信号50来过\n");
	}

	//恢复系统默认屏蔽的信号集
	sigprocmask(SIG_SETMASK,&old,NULL);

	return 0;
}









