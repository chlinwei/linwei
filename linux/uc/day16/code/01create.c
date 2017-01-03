//使用pthread_create函数创建新线程
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* pv)
{
	while(1)
	{
		printf("我是新线程!!!\n");
	}
}

int main(void)
{
	//typedef unsigned long int pthread_t;
	pthread_t tid;
	//调用pthread_create函数创建
	int res = pthread_create(&tid,NULL,task,NULL);
	if(0 != res)
	{
		printf("pthread_create: %s\n",strerror(res)),exit(-1);
	}
	usleep(100000); // 睡眠0.1秒
	printf("子线程的线程编号是：%lu,主线程的线程编号是：%lu\n",tid,pthread_self());
	return 0;
}








