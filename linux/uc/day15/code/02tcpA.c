//使用tcp模型实现一对多的通信
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

//定义全局变量，记录socket描述符
int sockfd;

void fa(int signo)
{
	printf("正在关闭服务器，请稍后...\n");
	sleep(3);
	int res = close(sockfd);
	if(-1 == res)
	{
		perror("close"),exit(-1);
	}
	printf("成功关闭服务器\n");
	exit(0);
}

int main(void)
{
	//1.创建socket，使用socket函数
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd)
	{
		perror("socket"),exit(-1);
	}
	printf("创建socket成功\n");
	//2.准备通信地址，使用结构体类型
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("192.168.1.102");
	//解决地址被占用的问题
/*	int reuseaddr = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&reuseaddr,sizeof(reuseaddr));*/
	//3.绑定socket和通信地址
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
	//7.采用信号2来关闭服务器
	signal(SIGINT,fa);
	printf("关闭服务器，请按ctrl+c...\n");
	//5.要求不断地响应客户端的连接请求
	while(1)
	{
		struct sockaddr_in recv_addr;
		socklen_t len = sizeof(recv_addr);
		int fd = accept(sockfd,(struct sockaddr*)&recv_addr,&len);
		if(-1 == fd)
		{
			perror("accept"),exit(-1);
		}
		char* ip = inet_ntoa(recv_addr.sin_addr);
		printf("客户端%s连接成功...\n",ip);
		//创建子进程去响应连接成功的客户端
		pid_t pid = fork();
		if(-1 == pid)
		{
			perror("fork"),exit(-1);
		}
		//子进程
		if(0 == pid)
		{
			while(1)
			{
				//6.读取客户端发来的数据
				char buf[100] = {0};
				res = read(fd,buf,sizeof(buf));
				if(-1 == res)
				{
					perror("read"),exit(-1);
				}
				//判断客户端发来是否为"bye"
				if(!strcmp(buf,"bye"))
				{
					printf("客户端%s已下线!\n",ip);
					break;//跳出循环
				}

				printf("客户端%s发来的消息是：%s\n",ip,buf);
				//再回发信息到客户端
				res = write(fd,"I received!",12);
				if(-1 == res)
				{
					perror("write"),exit(-1);
				}
			}
			//关闭与该客户端通信的描述符
			res = close(fd);
			if(-1 == res)
			{
				perror("close"),exit(-1);
			}
			//终止该子进程
			exit(0);
		}
	}
	return 0;
}







