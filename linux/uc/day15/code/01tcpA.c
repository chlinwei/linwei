//基于tcp协议的网络通信模型
#include <stdio.h>
#include <stdlib.h>
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
	//2.准备通信地址，使用结构体类型
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("172.30.100.41");
	//3.绑定socket和通信地址，使用bind函数
	int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(-1 == res)
	{
		perror("bind"),exit(-1);
	}
	printf("绑定成功\n");
	//4.监听，使用listen函数
	res = listen(sockfd,100);
	if(-1 == res)
	{
		perror("listen"),exit(-1);
	}
	printf("监听成功\n");
	//5.响应客户端连接请求，使用accept函数
	struct sockaddr_in recv_addr;
	socklen_t len = sizeof(recv_addr);
	int fd = accept(sockfd,(struct sockaddr*)&recv_addr,&len);
	if(-1 == fd)
	{
		perror("accept"),exit(-1);
	}
	printf("客户端%s连接成功...\n",inet_ntoa(recv_addr.sin_addr));
	//6.进行通信，使用read/write函数
	char buf[100] = {0};
	res = read(fd,buf,sizeof(buf));
	if(-1 == res)
	{
		perror("read"),exit(-1);
	}
	printf("客户端发来的消息是：%s,消息大小是：%d\n",buf,res);
	res = write(fd,"I received!",12);
	if(-1 == res)
	{
		perror("write"),exit(-1);
	}
	//7.关闭socket，使用close函数
	res = close(fd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	res = close(sockfd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("成功关闭socket\n");
	//练习：vi 01tcpB.c文件，编写客户端程序
	return 0;
}








