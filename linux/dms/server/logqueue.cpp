// 实现日志队列类
#include <iostream>
using namespace std;
#include "logqueue.h"
#define MAX_LOGS 10240
LogQueue g_logQueue;
// 构造器
LogQueue::LogQueue (void) {
	pthread_mutex_init (&m_mutex, NULL);
	pthread_cond_init (&m_nofull, NULL);
	pthread_cond_init (&m_noempty, NULL);
}
// 析构器
LogQueue::~LogQueue (void) {
	pthread_cond_destroy (&m_noempty);
	pthread_cond_destroy (&m_nofull);
	pthread_mutex_destroy (&m_mutex);
}
// 压入日志记录
LogQueue& LogQueue::operator<< (
	MLogRec const& log) {
	cout << "压入日志记录开始..." << endl;
	pthread_mutex_lock (&m_mutex);
	while (m_logs.size () >= MAX_LOGS) {
		cout << "等待日志队列非满..." << endl;
		pthread_cond_wait (&m_nofull,
			&m_mutex);
	}
	m_logs.push_back (log);
	pthread_cond_signal (&m_noempty);
	pthread_mutex_unlock (&m_mutex);
	cout << "压入日志记录完成。" << endl;
	return *this;
}
// 弹出日志记录
LogQueue& LogQueue::operator>> (
	MLogRec& log) {
	cout << "弹出日志记录开始..." << endl;
	pthread_mutex_lock (&m_mutex);
	while (m_logs.empty ()) {
		cout << "等待日志队列非空..." << endl;
		pthread_cond_wait (&m_noempty,
			&m_mutex);
	}
	log = m_logs.front ();
	m_logs.pop_front ();
	pthread_cond_signal (&m_nofull);
	pthread_mutex_unlock (&m_mutex);
	cout << "弹出日志记录完成。" << endl;
	return *this;
}
