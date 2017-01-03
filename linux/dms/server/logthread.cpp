// 实现线程类
#include <errno.h>
#include <cstring>
#include <iostream>
using namespace std;
#include "logthread.h"
// 启动线程
void LogThread::start (void)
	throw (ThreadException) {
	cout << "启动线程开始..." << endl;
	int error = pthread_create (&m_tid, NULL,
		run, this);
	if (error)
		throw ThreadException (
			strerror (error));
	cout << "启动线程完成。" << endl;
}
// 线程过程
void* LogThread::run (void* arg) {
	pthread_detach (pthread_self ());
	static_cast<LogThread*> (arg)-> run ();
	return NULL;
};
