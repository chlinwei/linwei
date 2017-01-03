// 声明文件数据访问对象类
#ifndef _FILEDAO_H
#define _FILEDAO_H
#include <fstream>
using namespace std;
#include "logdao.h"
// 文件数据访问对象
class FileDao : public LogDao {
public:
	// 构造器
	FileDao (string const& path)
		throw (DBException);
	// 析构器
	~FileDao (void);
	// 插入
	void insert (MLogRec const& log) throw ();
private:
	ofstream m_ofs; // 输出文件流
};
#endif // _FILEDAO_H
