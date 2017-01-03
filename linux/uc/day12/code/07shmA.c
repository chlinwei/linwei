//使用共享内存实现进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

//定义全局变量，来记录共享内存的ID
int shmid;

void fa(int signo)
{
	printf("正在删除共享内存，请稍后...\n");
	sleep(3);
	//使用shmctl函数来删除共享内存
	int res = shmctl(shmid,IPC_RMID,NULL);
	if(-1 == res)
	{
		perror("shmctl"),exit(-1);
	}
	printf("删除共享内存成功\n");
	exit(0); //结束进程
	//练习：vi 07shmB.c文件，打印共享内存中的数据即可
}

int main(void)
{
	//1.获取key值，使用ftok函数
	key_t key = ftok(".",100);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2.创建共享内存，使用shmget函数
	shmid = shmget(key,4,IPC_CREAT|IPC_EXCL|0664);
	if(-1 == shmid)
	{
		perror("shmget"),exit(-1);
	}
	printf("shmid = %d\n",shmid);
	//3.挂接共享内存，使用shmat函数
	void* pv = shmat(shmid,NULL,0);
	if((void*)-1 == pv)
	{
		perror("shmat"),exit(-1);
	}
	printf("挂接共享内存成功\n");
	//4.使用共享内存
	int* pi = pv;
	*pi = 100;
	//5.脱接共享内存，使用shmdt函数
	int res = shmdt(pv);
	if(-1 == res)
	{
		perror("shmdt"),exit(-1);
	}
	printf("脱接共享内存成功\n");
	//6.如果不再使用，则删除共享内存
	printf("删除共享内存，请按ctrl+c...\n");
	signal(SIGINT,fa);
	while(1);
	return 0;
}









