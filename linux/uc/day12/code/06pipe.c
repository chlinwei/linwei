//使用无名管道实现父子进程之间的通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	//准备一个数组
	int pipefd[2];

	//1.创建无名管道
	int res = pipe(pipefd);
	if(-1 == res)
	{
		perror("pipe"),exit(-1);
	}
	printf("创建无名管道成功\n");
	//2.使用fork函数创建子进程
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	//3.父进程给子进程发送数据
	if(0 == pid)
	{
		//关闭写端
		close(pipefd[1]);
		int i = 0;
		for(i = 1; i < 100; i++)
		{
			int x = 0;
			read(pipefd[0],&x,sizeof(int));
			printf("%d ",x);
		}
		printf("\n");
		//关闭读端
		close(pipefd[0]);
		exit(0);
	}
	//关闭读端
	close(pipefd[0]);
	int i = 0;
	for(i = 1; i < 100; i++)
	{
		write(pipefd[1],&i,sizeof(int));
	}
	//关闭写端
	close(pipefd[1]);
	return 0;
}










