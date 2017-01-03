//使用互斥量实现线程的同步问题
#include <stdio.h>
#include <pthread.h>

//定义全局数组作为共享资源
char* buf[5];
//记录数组的下标
int pos;
//1.定义互斥量
pthread_mutex_t mutex;

void* task(void* pv)
{
	//3.使用互斥量进行加锁
	pthread_mutex_lock(&mutex);
	//4.访问共享资源
	buf[pos] = pv;
	sleep(1);
	pos++;
	//5.使用互斥量进行解锁
	pthread_mutex_unlock(&mutex);
}

int main(void)
{
	//2.初始化互斥量
	pthread_mutex_init(&mutex,NULL);

	//使用pthread_create函数创建子线程
	pthread_t tid;
	pthread_create(&tid,NULL,task,"zhangfei");
	pthread_t tid2;
	pthread_create(&tid2,NULL,task,"guanyu");
	//使用pthread_join函数来等待子线程
	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);
	
	//6.销毁互斥量
	pthread_mutex_destroy(&mutex);

	//循环遍历字符指针数组中字符串
	int i = 0;
	for(i = 0; i < pos; i++)
	{
		printf("%s ",buf[i]);
	}
	printf("\n");
	return 0;
}








