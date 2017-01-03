//使用pthread_cancel函数取消线程
#include <stdio.h>
#include <pthread.h>

void* task(void* pv)
{
	// 设置该线程不可以被取消,默认可以取消

	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
//	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE，NULL);

	while(1)
	{
		printf("I am superman!\n");
		usleep(100000);
	}
}

void* task2(void* pv)
{
	printf("开始取消线程...\n");
	usleep(500000);
	pthread_cancel(*(pthread_t*)pv);
	printf("取消线程结束\n");
}

int main(void)
{
	//1.创建子线程
	pthread_t tid;
	pthread_create(&tid,NULL,task,NULL);
	pthread_t tid2;
	pthread_create(&tid2,NULL,task2,&tid);
	//2.等待子线程结束
	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);
	return 0;
}







