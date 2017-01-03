//使用信号量集实现进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(void)
{
	//1.获取key值，使用ftok函数
	key_t key = ftok(".",200);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2.获取信号量集，使用semget函数
	int semid = semget(key,0,0);
	if(-1 == semid)
	{
		perror("semget"),exit(-1);
	}
	printf("semid = %d\n",semid);
	//3.创建10个子进程去模拟抢占资源过程
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		pid_t pid = fork();
		if(-1 == pid)
		{
			perror("fork"),exit(-1);
		}
		// 子进程
		if(0 == pid)
		{
			//准备结构体变量
			struct sembuf sem;
			sem.sem_num = 0;//信号量集下标
			sem.sem_op = -1;//减1
			sem.sem_flg = 0;//默认阻塞
			//用信号量的值减1来模拟抢占资源
			int res = semop(semid,&sem,1/*结构体数量*/);
			if(-1 == res)
			{
				perror("semop"),exit(-1);
			}
			printf("申请共享资源成功\n");
			sleep(20);//模拟占用资源
			printf("释放共享资源\n");
			sem.sem_op = 1;
			semop(semid,&sem,1);
			//终止子进程
			exit(0);
		}
	}
	return 0;
}











