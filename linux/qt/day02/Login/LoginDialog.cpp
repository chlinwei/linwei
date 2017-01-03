#include <QtGui>
#include "LoginDialog.h"

LoginDialog::LoginDialog(QWidget* parent
	/*=NULL*/):QDialog(parent){
	setupUi(this);
	connect(m_btnBox,SIGNAL(accepted()),
		this,SLOT(onAccepted()));
	connect(m_btnBox,SIGNAL(rejected()),
		this,SLOT(onRejected()));
}
void LoginDialog::onAccepted(void){
	if(m_editUsername->text() == "tarena" &&
	 	m_editPassword->text()=="123456"){
		close();//关闭窗口
	}
	else{
		QMessageBox msgBox(//消息框
			QMessageBox::Critical,//风格
			windowTitle(),//标题
			tr("用户名或密码错误,登陆失败"),
			QMessageBox::Ok,//提示按钮
			this);//父窗口
		msgBox.exec();
	}
}
void LoginDialog::onRejected(void){
	QMessageBox msgBox(QMessageBox::Question,
		windowTitle(),tr("确定要取消吗?"),
		QMessageBox::Yes|QMessageBox::No,
		this);
	if(msgBox.exec()== QMessageBox::Yes){
		close();
	}
}




