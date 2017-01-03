//基于udp协议的通信模型
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
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
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
	//4.进行通信，使用sendto/recvfrom函数
	while(1)
	{
		char buf[100] = {0};
		//res = read(sockfd,buf,sizeof(buf));
		struct sockaddr_in recv_addr;
		socklen_t len = sizeof(recv_addr);
		res = recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&recv_addr,&len);
		if(-1 == res)
		{
			perror("recvfrom"),exit(-1);
		}
		//获取客户端的IP地址
		char* ip = inet_ntoa(recv_addr.sin_addr);
		printf("客户端%s发来的消息是：%s,消息大小是：%d\n",ip,buf,res);
		//向客户端回发消息
		res = sendto(sockfd,"I received!",12,0,(struct sockaddr*)&recv_addr,len);
		if(-1 == res)
		{
			perror("sendto"),exit(-1);
		}
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
















