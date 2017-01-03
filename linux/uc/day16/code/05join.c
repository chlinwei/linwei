//使用pthread_join函数等待线程
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* pv)
{
	int i = 0;
	//static int sum = 0;
	int sum = 0;
	for(i = 1; i <= 100; i++)
	{
		sum += i;
	}
	//永远不要返回局部变量的地址
	//return &sum;
	return (void*)sum;
}

int main(void)
{
	//1.创建子线程，计算1~ 100之间的和
	pthread_t tid;
	int res = pthread_create(&tid,NULL,task,NULL);
	if(0 != res)
	{
		printf("pthread_create: %s\n",strerror(res));
		exit(-1);
	}
	//2.等待子线程结束，并打印结果
	/*
	int* pi = NULL;
	res = pthread_join(tid,(void**)&pi);
	if(0 != res)
	{
		printf("pthread_join: %s\n",strerror(res));
		exit(-1);
	}
	printf("*pi = %d\n",*pi); // 5050
	*/
	int result = 0;
	//通过pthread_detach函数设置为分离状态
	pthread_detach(tid);

	res = pthread_join(tid,(void**)&result);
	if(0 != res)
	{
		printf("pthread_join: %s\n",strerror(res));
		exit(-1);
	}
	printf("result = %d\n",result);//5050
	return 0;
}









