#include"logindlg.h"
CLoginDlg::CLoginDlg(QWidget* parent)
	:QDialog(parent)
{
	QLabel* usrLabel=new QLabel(tr("用户名:"))	;
	QLabel* pwdLabel=new QLabel(tr("密码:"));
	usrLineEdit=new QLineEdit;
	pwdLineEdit=new QLineEdit;
	pwdLineEdit->setEchoMode(QLineEdit::Password);
	//setEchoMode 设置行编辑器的显示方式
	//通常有三种
	//QLineEdit::Normal,默认的显示方式,显示用户实际输入的内容
	//QLienEdit::Password,用*代替用户实际输入的内容
	//QLineEdit::NoEcho不显示用户输入的内容

	//QLineExit::PasswordEchoOnEdit,仅仅用户在行编辑器输入
	//文本的内容时,才显示用户输入的内容,而在用户输入完成后
	//以*代替
	QGridLayout* gridLayout=new QGridLayout;
	//网格布局管理器
	gridLayout->addWidget(usrLabel,0,0,1,1);
	//(lineEdit,行号,列号,行跨度,列跨度)
	gridLayout->addWidget(usrLineEdit,0,1,1,3);
	gridLayout->addWidget(pwdLabel,1,0,1,1);
	gridLayout->addWidget(pwdLineEdit,1,1,1,3);
	QPushButton* okBtn=new QPushButton(tr("登陆"));
	//QPushButton(const QString& text,QWidget* parent=NULL)
	QPushButton* cancelBtn=new QPushButton(tr("取消"));
	QHBoxLayout* btnLayout=new QHBoxLayout;
	//QHBoxLayout创建的对象,addWidget添加部件从左到右边
	btnLayout->setSpacing(60);
	btnLayout->addWidget(okBtn);
	//从左到右间隔60,登陆和取消之间间隔60
	btnLayout->addWidget(cancelBtn);
	QVBoxLayout* dlgLayout=new QVBoxLayout;
	//QVBoxLayout创建的对象addLayout添加的布局器
	//从上到下
	dlgLayout->setMargin(40);
	//Margin:边缘 setMargin设置布局器的边缘宽度为40
	//即内部子窗口距离布局管理器边界
	dlgLayout->addLayout(gridLayout);
	//dlgLayout布局器管理两个布局器,gridLayout,btnLayout
	dlgLayout->addStretch(40);
	//gridLayout和btnLayout之间相距40
	dlgLayout->addLayout(btnLayout);
	setLayout(dlgLayout);
	connect(okBtn,SIGNAL(clicked()),this,SLOT(accept()));
	//当点击登陆按钮时能够进行用户名的密码的验证
	connect(cancelBtn,SIGNAL(clicked()),this,SLOT(reject()));
	//使得对话框能够相应用户的退出操作
	//QDialog::reject()将会隐藏对话框并将对话框的
	//返回代码设置为QDialog::Rejected,此时对话框将
	//关闭,启动对话框的槽函数,QDialog::exec()
	//将返回运行结果QDialog::Rejected
	setWindowTitle(tr("登陆"));
	//设置对话框的标题为"登陆"
	resize(300,200);
	//高300宽200
}
//为了实现对"用户名",和"密码"的有效验证
//重写了QDialog的虚槽函数accept()该函数响应用户
//单击""
	void CLoginDlg::accept()
{
	if(usrLineEdit->text().trimmed()==tr("lcf")&& pwdLineEdit->text()==tr("lcf"))
		//这里pwdLineEdit为什么没有用trimmed
		//QString text()const
		//QString trimmed()const
		//会移除外在的空格但不会移除内在的空格
		//QString str="   lots\t of\nwhitespace\r\n ";
		//str="lots\t of\nwhitespace"
	{
		QDialog::accept();
		//void QDialog::accept()[virtual slot]
		//Hides the modal dialog and sets the result code to Accepted
	}
	else
	{
		QMessageBox::warning(this,tr("警告"),
				tr("用户或密码错误!"),
				QMessageBox::Yes);
		usrLineEdit->setFocus();
	}
}
