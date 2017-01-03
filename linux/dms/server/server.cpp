// 实现服务器类
#include "server.h"
// 构造器
Server::Server (LogDao& dao, short port,
	string const& ip /* = "" */)
	throw (ServerException) :
	m_store (dao), m_socket (port, ip) {}
// 数据采集
void Server::dataMine (void)
	throw (ServerException) {
	// 启动存储线程
	m_store.start ();
	// 等待客户连接
	m_socket.acceptClient ();
}
