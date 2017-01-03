#ifndef __LOGINDIALOG_H
#define __LOGINDIALOG_H
#include <QDialog>
#include "ui_LoginDialog.h"

class LoginDialog:public QDialog,
	public Ui::LoginDialog{
	Q_OBJECT
public:
	LoginDialog(QWidget* parent = NULL);
private slots:
	void onAccepted(void);//确定槽函数
	void onRejected(void);//取消槽函数
};
#endif//__LOGINDIALOG_H
