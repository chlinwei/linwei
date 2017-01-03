//使用waitpid函数等待子进程的状态发生改变
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	//1.使用fork函数创建2个子进程
	pid_t pid,pid2;
	pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	// 父进程
	if(0 != pid)
	{
		pid2 = fork();
	}
	//printf("test\n");
	//2.两个子进程各自分别执行
	if(0 == pid)
	{
		printf("子进程一%d开始执行...\n",getpid());
		sleep(10);
		printf("子进程一结束\n");
		exit(100);
	}
	if(0 == pid2)
	{
		printf("子进程二%d开始执行...\n",getpid());
		sleep(15);
		printf("子进程二结束\n");
		exit(200);
	}
	//3.父进程等待子进程状态发生改变，打印
	printf("父进程开始等待...\n");
	int status = 0;
	// 等待任意一个子进程结束
	//int res = waitpid(-1,&status,0);
	// 等待进程号为pid的子进程，子进程一
	//int res = waitpid(pid,&status,0);
	// 等待进程号为pid2的子进程，子进程二
	int res = waitpid(pid2,&status,0);
	if(-1 == res)
	{
		perror("waitpid"),exit(-1);
	}
	if(WIFEXITED(status))
	{
		printf("终止的子进程是：%d,该进程的退出状态是：%d\n",res,WEXITSTATUS(status));
	}
	return 0;
}










