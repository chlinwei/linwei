// 声明客户线程类
#ifndef _CLIENTTHREAD_H
#define _CLIENTTHREAD_H
#include "logthread.h"
// 客户线程
class ClientThread : public LogThread {
public:
	// 构造器
	ClientThread (int connfd);
private:
	// 线程处理
	void run (void);
	int m_connfd; // 连接套接字
};
#endif // _CLIENTTHREAD_H
