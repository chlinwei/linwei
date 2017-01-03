//观察使用fork函数创建的父子进程之间的关系
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int i1 = 1;//全局变量  数据区/全局区

int main(void)
{
	int i2 = 1;//局部变量  栈区
	// pc指向堆区  pc本身在栈区
	char* pc = (char*)malloc(sizeof(char)*10);
	strcpy(pc,"hello");

	//使用fork函数创建子进程
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	// 子进程
	if(0 == pid)
	{
		i1 = 2;
		i2 = 2;
		strcpy(pc,"word");
		printf("子进程中：i1 = %d,i2 = %d,pc = %s\n",i1,i2,pc);
		exit(0);//终止子进程
	}
	printf("父进程中：i1 = %d,i2 = %d,pc = %s\n",i1,i2,pc);
	return 0;
}










