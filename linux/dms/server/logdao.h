// 定义数据访问对象接口类
#ifndef _LOGDAO_H
#define _LOGDAO_H
#include "data.h"
#include "except.h"
// 数据访问对象接口
class LogDao {
public:
	virtual ~LogDao (void) {}
	// 插入
	virtual void insert (MLogRec const& log)
		throw (DBException) = 0;
};
#endif // _LOGDAO_H
