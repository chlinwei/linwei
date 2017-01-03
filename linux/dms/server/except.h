// 定义异常类
#ifndef _EXCEPT_H
#define _EXCEPT_H
#include <string>
using namespace std;
// 服务器异常
class ServerException : public exception {
public:
	ServerException (void) :
		m_msg ("服务器异常！") {}
	ServerException (string const& msg) :
		m_msg ("服务器异常：") {
		m_msg += msg;
		m_msg += "！";
	}
	~ServerException (void) throw () {}
	char const* what (void) const throw () {
		return m_msg.c_str ();
	}
private:
	string m_msg;
};
// 数据库异常
class DBException :
	public ServerException {
public:
	DBException (void) :
		ServerException ("数据库错误") {}
	DBException (string const& msg) :
		ServerException (msg) {}
};
// 网络异常
class SocketException :
	public ServerException {
public:
	SocketException (void) :
		ServerException ("网络错误") {}
	SocketException (string const& msg) :
		ServerException (msg) {}
};
// 线程异常
class ThreadException :
	public ServerException {
public:
	ThreadException (void) :
		ServerException ("线程错误") {}
	ThreadException (string const& msg) :
		ServerException (msg) {}
};
#endif // _EXCEPT_H
