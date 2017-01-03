// 实现客户线程类
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
using namespace std;
#include "clientthread.h"
#include "logqueue.h"
// 构造器
ClientThread::ClientThread (int connfd) :
	m_connfd (connfd) {}
// 线程处理
void ClientThread::run (void) {
	MLogRec log;
	for (;;) {
		ssize_t rlen;
		for (size_t len = sizeof (log); len;
			len -= rlen) {
			rlen = recv (m_connfd,
				(char*)&log + sizeof (log) -
				len, len, 0);
			if (rlen <= 0)
				goto escape;
		}
		log.pid       =ntohl (log.pid);
		log.logintime =ntohl (log.logintime);
		log.logouttime=ntohl (log.logouttime);
		log.durations =ntohl (log.durations);
		g_logQueue << log;
	}
escape:
	close (m_connfd);
	delete this;
}
