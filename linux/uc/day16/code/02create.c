//使用pthread_create函数创建新线程
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* pv)
{
	// void* pv = &num;
	int* pi = pv;
	*pi = 200;// pi = pv = &num; *pi = num	
}

int main(void)
{
	int num = 100;
	//使用pthread_create函数创建
	pthread_t tid;
	int res = pthread_create(&tid,NULL,task,&num);
	if(0 != res)
	{
		printf("pthread_create: %s\n",strerror(res));
		exit(-1);
	}
	sleep(1);
	printf("修改之后num = %d\n",num); //200
	return 0;
}










