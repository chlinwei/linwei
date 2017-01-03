//使用pthread_exit函数来终止线程
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* task(void* pv)
{
	static int i = 0;
	for(i = 1; i < 20; i++)
	{
		printf("i = %d\n",i);
		//当 i = 10时，将i的数值返回
		if(10 == i)
		{
			//return &i;
			//pthread_exit(&i);
			exit(-1); //结束整个进程
		}
	}
}

int main(void)
{
	//1.创建子线程，执行线程处理函数
	pthread_t tid;
	pthread_create(&tid,NULL,task,NULL);
	//2.等待子线程结束，接收退出状态信息
	int* pi = NULL;
	pthread_join(tid,(void**)&pi);
	printf("*pi = %d\n",*pi); // 10
	return 0;
}







