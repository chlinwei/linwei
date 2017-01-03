//使用pthread_join函数等待子线程
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* task(void* pv)
{
	// pc指向只读常量区，pc本身在栈区
	char* pc = "hello";//pc本身在堆区，pc指针的内容在只读存储区
	//只读存储区的内容不会在函数结束后被释放
	return pc;//返回字符串的首地址
}

int main(void)
{
	//1.使用pthread_create创建子线程
	pthread_t tid;
	int res = pthread_create(&tid,NULL,task,NULL);
	if(0 != res)
	{
		printf("pthread_create: %s\n",strerror(res));
		exit(-1);
	}
	//2.使用pthread_join函数等待子线程
	char* pc = NULL;
	res = pthread_join(tid,(void**)&pc);
	if(0 != res)
	{
		printf("pthread_join: %s\n",strerror(res));
		exit(-1);
	}
	printf("pc = %s\n",pc); // hello
	return 0;
}










