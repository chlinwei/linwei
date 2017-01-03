// 实现存储线程类
#include <iostream>
using namespace std;
#include "storethread.h"
#include "logqueue.h"
// 构造器
StoreThread::StoreThread (LogDao& dao) :
	m_dao (dao) {}
// 线程处理
void StoreThread::run (void) {
	MLogRec log;
	for (;;) {
		g_logQueue >> log;
		try {
			m_dao.insert (log);
		}
		catch (DBException& ex) {
			cout << ex.what () << endl;
		}
	}
}
