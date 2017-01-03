//使用消息队列实现进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//定义消息的数据类型
typedef struct
{
	long mtype;//消息的类型
	char buf[20];//消息的内容
}Msg;

int main(void)
{
	//1.获取key值，使用ftok函数
	key_t key = ftok(".",150);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2.获取消息队列，使用msgget函数
	int msgid = msgget(key,0);
	if(-1 == msgid)
	{
		perror("msgget"),exit(-1);
	}
	printf("msgid = %d\n",msgid);
	//3.接受消息队列中的一个消息，打印
	Msg msg = {};
	//始终接受消息队列中的第一个消息
	//int res = msgrcv(msgid,&msg,sizeof(msg.buf),0,0);
	//始终接收消息队列中第一个类型为1的消息
	//int res = msgrcv(msgid,&msg,sizeof(msg.buf),1,0);
	//先读取类型为1的消息，再读类型为2消息
	int res = msgrcv(msgid,&msg,sizeof(msg.buf),-2,0);
	if(-1 == res)
	{
		perror("msgrc"),exit(-1);
	}
	printf("接收到的消息是：%ld,%s\n",msg.mtype,msg.buf);
	return 0;
}










