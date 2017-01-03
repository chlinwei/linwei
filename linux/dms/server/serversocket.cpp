// 实现服务器套接字类
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <cstring>
#include <iostream>
using namespace std;
#include "serversocket.h"
#include "clientthread.h"
// 构造器
ServerSocket::ServerSocket (short port,
	string const& ip /* = "" */)
	throw (SocketException) {
	cout << "初始化服务器开始..." << endl;
	// 创建套接字
	if ((m_sockfd = socket (AF_INET,
		SOCK_STREAM, 0)) == -1)
		throw SocketException (
			strerror (errno));
	// 允许地址重用
	int on = 1;
	if (setsockopt (m_sockfd, SOL_SOCKET,
		SO_REUSEADDR, &on,
		sizeof (on)) == -1) {
		close (m_sockfd);
		throw SocketException (
			strerror (errno));
	}
	// 设置地址结构并绑定
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons (port);
	addr.sin_addr.s_addr = ip.empty () ?
		INADDR_ANY : inet_addr (ip.c_str ());
	if (bind (m_sockfd, (sockaddr*)&addr,
		sizeof (addr)) == -1) {
		close (m_sockfd);
		throw SocketException (
			strerror (errno));
	}
	// 侦听
	if (listen (m_sockfd, 1024) == -1) {
		close (m_sockfd);
		throw SocketException (
			strerror (errno));
	}
	cout << "初始化服务器完成。" << endl;
}
// 等待客户机连接
void ServerSocket::acceptClient (void)
	throw (SocketException) {
	for (;;) {
		cout << "等待客户机连接..." << endl;
		sockaddr_in addrcli;
		socklen_t addrlen = sizeof (addrcli);
		int connfd = accept (m_sockfd,
			(sockaddr*)&addrcli, &addrlen);
		if (connfd == -1) {
			close (m_sockfd);
			throw SocketException (
				strerror (errno));
		}
		(new ClientThread (connfd))->start ();
	}
}
