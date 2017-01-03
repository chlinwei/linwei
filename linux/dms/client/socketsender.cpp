// 实现网络日志发送器类
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include "socketsender.h"
// 构造器
SocketSender::SocketSender (
	string const& failFile, short port,
	string const& ip /* = "127.0.0.1" */,
	WorkThread* work /* = NULL */) :
	m_failFile (failFile), m_port (port),
	m_ip (ip), m_work (work) {}
// 发送日志
void SocketSender::sendLog (
	list<MLogRec>& logs)
	throw (ClientException) {
	cout << "发送日志开始..." << endl;
	try {
		try {
			// 读取发送失败文件
			readFailFile (logs);
		}
		catch (ReadException& ex) {
			cout << "无发送失败文件！"
				<< endl;
		}
		// 连接服务器
		connectServer ();
		// 发送数据
		sendData (logs);
	}
	catch (SocketException& ex) {
		// 保存发送失败文件
		saveFailFile (logs);
		throw;
	}
	catch (SendException& ex) {
		// 保存发送失败文件
		saveFailFile (logs);
		throw;
	}
	cout << "发送日志完成。" << endl;
}
// 读取发送失败文件
void SocketSender::readFailFile (
	list<MLogRec>& logs)
	throw (ReadException) {
	cout << "读取发送失败文件开始..." << endl;
	ifstream ifs (m_failFile.c_str (),
		ios::binary);
	if (! ifs)
		throw ReadException (
			"发送失败文件无法打开");
	MLogRec log;
	while (ifs.read ((char*)&log,
		sizeof (log)))
		logs.push_front (log);
	if (! ifs.eof ())
		throw ReadException (
			"发送失败文件无法读取");
	ifs.close ();
	unlink (m_failFile.c_str ());
	cout << "读取发送失败文件完成。" << endl;
}
// 连接服务器
void SocketSender::connectServer (void)
	throw (SocketException) {
	cout << "连接服务器开始..." << endl;
	// 创建套接字
	if ((m_sockfd = socket (AF_INET,
		SOCK_STREAM, 0)) == -1)
		throw SocketException (
			strerror (errno));
	// 准备地址结构
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons (m_port);
	addr.sin_addr.s_addr = inet_addr (
		m_ip.c_str ());
	// 建立与服务器的连接
	if (connect (m_sockfd, (sockaddr*)&addr,
		sizeof (addr)) == -1) {
		close (m_sockfd);
		throw SocketException (
			strerror (errno));
	}
	cout << "连接服务器完成。" << endl;
}
// 发送数据
void SocketSender::sendData (
	list<MLogRec>& logs)
	throw (SendException) {
	cout << "发送数据开始..." << endl;
	while (! logs.empty ()) {
		MLogRec log = logs.front ();
		log.pid       =htonl (log.pid);
		log.logintime =htonl (log.logintime);
		log.logouttime=htonl (log.logouttime);
		log.durations =htonl (log.durations);
		if (send (m_sockfd, &log,
			sizeof (log), 0) == -1) {
			close (m_sockfd);
			throw SendException (
				strerror (errno));
		}
		if (m_work) {
			ostringstream oss;
			oss << logs.front ();
			m_work->update (oss.str ());
		}
		logs.pop_front ();
	}
	close (m_sockfd);
	cout << "发送数据完成。" << endl;
}
// 保存发送失败文件
void SocketSender::saveFailFile (
	list<MLogRec>& logs)
	throw (SaveException) {
	cout << "保存发送失败文件开始..." << endl;
	if (! logs.empty ()) {
		ofstream ofs (m_failFile.c_str (),
			ios::binary);
		if (! ofs)
			throw SaveException (
				"发送失败文件无法打开");
		while (! logs.empty ()) {
			ofs.write ((char const*)
				&logs.front (),
				sizeof (MLogRec));
			logs.pop_front ();
		}
		ofs.close ();
	}
	cout << "保存发送失败文件完成。" << endl;
}
