// 声明Oracle数据访问对象类
#ifndef _ORACLEDAO_H
#define _ORACLEDAO_H
#include "logdao.h"
// Oracle数据访问对象
class OracleDao : public LogDao {
public:
	// 构造器
	OracleDao (string const& username,
		string const& password)
		throw (DBException);
	// 析构器
	~OracleDao (void);
	// 插入
	void insert (MLogRec const& log)
		throw (DBException);
};
#endif // _ORACLEDAO_H
