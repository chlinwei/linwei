// 声明工作线程类
#ifndef _WORKTHREAD_H
#define _WORKTHREAD_H
#include <QThread>
#include <QString>
#include <string>
using namespace std;
// 工作线程
class WorkThread : public QThread {
	Q_OBJECT
public:
	void run (void);
	void update (string const& text);
signals:
	void update (QString const& text);
};
#endif // _WORKTHREAD_H
