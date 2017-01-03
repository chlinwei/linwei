//使用消息队列实现进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>

//定义消息的数据类型
typedef struct
{
	long mtype;//消息的类型
	char buf[20];//消息的内容
}Msg;

//定义全局变量记录消息队列的ID
int msgid;

void fa(int signo)
{
	printf("正在删除消息队列，请稍后...\n");
	sleep(3);
	//使用msgctl函数进行删除
	int res = msgctl(msgid,IPC_RMID,NULL);
	if(-1 == res)
	{
		perror("msgctl"),exit(-1);
	}
	printf("删除消息队列成功\n");
	exit(0); //终止进程
}

int main(void)
{
	//1.获取key值，使用ftok函数
	key_t key = ftok(".",150);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2.创建消息队列，使用msgget函数
	msgid = msgget(key,IPC_CREAT|IPC_EXCL|0664);
	if(-1 == msgid)
	{
		perror("msgget"),exit(-1);
	}
	printf("msgid = %d\n",msgid);
	//3.发送消息到消息队列，使用msgsnd函数
	Msg msg1 = {1,"hello1"};
	Msg msg2 = {2,"hello2"};
	int res = msgsnd(msgid,&msg2,sizeof(msg2.buf),0);
	if(-1 == res)
	{
		perror("msgsnd"),exit(-1);
	}
	res = msgsnd(msgid,&msg1,sizeof(msg1.buf),0);
	if(-1 == res)
	{
		perror("msgsnd"),exit(-1);
	}
	printf("发送消息到消息队列成功\n");
	//4.如果不再使用，则删除消息队列
	printf("删除消息队列，请按ctrl+c...\n");
	signal(SIGINT,fa);
	while(1);
	return 0;
}









