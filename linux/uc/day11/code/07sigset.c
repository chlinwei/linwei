//信号集的概念和使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(void)
{
	//定义信号集类型的变量
	sigset_t set;
	printf("sizeof(sigset_t) = %d\n",sizeof(sigset_t)); // 128
	printf("set = %d\n",set); // 随机数
//清空信号集
	int res = sigemptyset(&set);
	if(-1 == res)
	{
		perror("sigemptyset"),exit(-1);
	}
	printf("set = %d\n",set); // 0
	//增加信号2 信号3  信号7到信号集中
	res = sigaddset(&set,2);
	if(-1 == res)
	{
		perror("sigaddset"),exit(-1);
	}
	printf("set = %d\n",set); // 2/////信号是从1.2.3.4开始的
	//2.就是2^1=2
	res = sigaddset(&set,3);
	if(-1 == res)
	{
		perror("sigaddset"),exit(-1);
	}
	printf("set = %d\n",set); // 6 = 4+2//2+2^2=6
	res = sigaddset(&set,7);
	if(-1 == res)
	{
		perror("sigaddset"),exit(-1);
	}
	printf("set = %d\n",set);// 70 = 64+6//6+2^6=70

	//删除信号3从信号集中
	res = sigdelset(&set,3);
	if(-1 == res)
	{
		perror("sigdelset"),exit(-1);
	}
	printf("set = %d\n",set); // 66
	//判断信号2 信号3  信号7是否存在
	if(sigismember(&set,2) == 1)//sigismember有点特别
		//返回1说明指定的信号存在,如果返回0说明指定的信号不存在
		//返回-1说明出错
	{
		printf("信号2存在\n");
	}
	if(sigismember(&set,3) == 1)
	{
		printf("信号3存在\n");
	}
	if(sigismember(&set,7)==1)
	{
		printf("信号7存在\n");
	}
	//填满信号集
	res = sigfillset(&set);
	if(-1 == res)
	{
		perror("sigfillset"),exit(-1);
	}
	printf("set = %d\n",set); // 很大的数
	return 0;
}










