// 声明存储线程类
#ifndef _STORETHREAD_H
#define _STORETHREAD_H
#include "logthread.h"
#include "logdao.h"
// 存储线程
class StoreThread : public LogThread {
public:
	// 构造器
	StoreThread (LogDao& dao);
private:
	// 线程处理
	void run (void);
	LogDao& m_dao; // 数据访问对象
};
#endif // _STORETHREAD_H
