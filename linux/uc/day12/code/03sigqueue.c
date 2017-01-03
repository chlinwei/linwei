//使用sigqueue函数发送信号和附加数据
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void fa(int signo,siginfo_t* info,void* p)
{
	printf("进程%d发来了信号%d,发送的附加数据是：%d\n",info->si_pid,signo,info->si_value);
}

int main(void)
{
	//准备结构体变量
	struct sigaction action = {};
	//使用第二个函数指针处理信号
	action.sa_sigaction = fa;
	action.sa_flags = SA_SIGINFO;

	//使用sigaction函数对信号40自定义处理
	sigaction(40,&action,NULL);
	//使用fork函数创建子进程
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	//使用子进程给父进程发信号和附加数据
	if(0 == pid)
	{
		printf("子进程%d开始执行\n",getpid());
		int i = 0;
		for(i = 0; i < 100; i++)
		{
			//准备联合变量
			union sigval value;
			value.sival_int = i;
			sigqueue(getppid(),40,value);
		}
		//终止子进程
		exit(0);
	}
	while(1);
	return 0;
}











