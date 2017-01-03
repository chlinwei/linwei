// 声明服务器类
#ifndef _SERVER_H
#define _SERVER_H
#include <string>
using namespace std;
#include "storethread.h"
#include "serversocket.h"
// 服务器
class Server {
public:
	// 构造器
	Server (LogDao& dao, short port,
		string const& ip = "")
		throw (ServerException);
	// 数据采集
	void dataMine (void) throw (ServerException);
private:
	StoreThread  m_store;  // 存储线程
	ServerSocket m_socket; // 服务器套接字
};
#endif // _SERVER_H
