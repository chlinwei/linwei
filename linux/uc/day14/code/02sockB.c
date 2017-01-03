//基于socket的本地通信
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

int main(void)
{
	//1.创建socket，使用socket函数
	int sockfd = socket(AF_UNIX,SOCK_DGRAM,0);
	if(-1 == sockfd)
	{
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	//2.准备通信地址，使用服务器的地址
	struct sockaddr_un addr;
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path,"a.sock");
	//3.连接socket和通信地址，用connect函数
	int res = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res)
	{
		perror("connect"),exit(-1);
	}
	printf("连接服务器成功\n");
	//4.进行通信，使用read/write函数
	res = write(sockfd,"hello",6);
	if(-1 == res)
	{
		perror("write"),exit(-1);
	}
	printf("成功发送数据到服务器，发送的数据大小是：%d\n",res);
	//5.关闭socket，使用close函数
	res = close(sockfd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("成功关闭socket\n");
	return 0;
}










