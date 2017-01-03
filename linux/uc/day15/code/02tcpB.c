//基于tcp模型的一对多通信
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void)
{
	//1.创建socket，使用socket函数
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd)
	{
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	//2.准备通信地址，服务器的地址
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("192.168.1.102");
	//3.连接socket和通信地址，connect函数
	int res = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res)
	{
		perror("connect"),exit(-1);
	}
	printf("连接服务器成功\n");
	//4.不断地和服务器进行通信,read/write
	while(1)
	{
		char buf[100] = {0};
		printf("请输入要发送的内容：\n");
		scanf("%s",buf);
		//发送数据到服务器中
		res = write(sockfd,buf,strlen(buf));
		if(-1 == res)
		{
			perror("write"),exit(-1);
		}
		//判断客户端是否下线
		if(!strcmp(buf,"bye"))
		{
			printf("客户端下线了...\n");
			break;
		}
		//接受服务器发来的数据
		char buf2[100] = {0};
		res = read(sockfd,buf2,sizeof(buf2));
		if(-1 == res)
		{
			perror("read"),exit(-1);
		}
		printf("服务器发来的数据是：%s\n",buf2);
	}
	//5.关闭socket，使用close函数
	res = close(sockfd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("成功关闭socket\n");
	return 0;
}










