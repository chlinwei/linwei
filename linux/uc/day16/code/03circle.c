//使用子线程计算圆形的周长和面积
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* pv)
{
	sleep(10);
	int ir = *(int*)pv;
	printf("圆形的周长是%lf,面积是：%lf\n",2*3.14*ir,3.14*ir*ir);
	return NULL;
}

int main(void)
{
	//1.申请动态内存，提示用户输入半径
	int* pi = (int*)malloc(sizeof(int));
	if(NULL == pi)
	{
		perror("malloc"),exit(-1);
	}
	printf("请输入一个半径：\n");
	scanf("%d",pi);
	//2.创建子线程，计算周长和面积
	pthread_t tid;
	pthread_create(&tid,NULL,task,pi);
	//sleep(1);
	//使用pthread_join函数等待子线程
	pthread_join(tid,NULL);
	//3.释放动态内存
	free(pi);
	pi = NULL;
	return 0;
}






