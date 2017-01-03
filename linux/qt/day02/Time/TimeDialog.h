#ifndef __TIMEDIALOG_H
#define __TIMEDIALOG_H
#include <QDialog>
#include <QLabel>
class TimeDialog:public QDialog{
 	Q_OBJECT
public:
	TimeDialog(QWidget* parent = NULL);
private:
	QLabel* m_labTime;
private slots:
	void timeClicked(void);
//声明自定义信号
signals:
	void setText(const QString&);
};
#endif //__TIMEDIALOG_H

