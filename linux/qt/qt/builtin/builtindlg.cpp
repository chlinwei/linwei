#include"builtindlg.h"
CBuiltinDlg::CBuiltinDlg(QWidget* parent)
	:QDialog(parent)
{
	displayTextEdit=new QTextEdit(tr("Qt的标准通用对话框"));
	QGridLayout* gridLayout=new QGridLayout;
	colorPushBtn=new QPushButton(tr("颜色对话框"));
	errorPushBtn=new QPushButton(tr("错误消息框"));
	filePushBtn=new QPushButton(tr("文件对话框"));
	fontPushBtn=new QPushButton(tr("字体对话框"));
	inputPushBtn=new QPushButton(tr("输入对话框"));
	pagePushBtn=new QPushButton(tr("页设置对话框"));
	progressPushBtn=new QPushButton(tr("进度对话框"));
	printPushBtn=new QPushButton(tr("打印对话框"));
	gridLayout->addWidget(colorPushBtn,0,0,1,1);
	gridLayout->addWidget(errorPushBtn,0,1,1,1);
	gridLayout->addWidget(filePushBtn,0,2,1,1);
	gridLayout->addWidget(fontPushBtn,1,0,1,1);
	gridLayout->addWidget(inputPushBtn,1,1,1,1);
	gridLayout->addWidget(pagePushBtn,1,2,1,1);
	gridLayout->addWidget(progressPushBtn,2,0,1,1);
	gridLayout->addWidget(printPushBtn,2,1,1,1);
	gridLayout0>addWidget(displayTextEdit,3,0,3,3);
	setLayout(gridLayout);
	connect(colorPushBtn,SIGNAL(clicked()),this,
				SLOT(doPushBtn()));
	connect(errorPushBtn,SIGNAL(clicked()),this,
				SLOT(doPushBtn()));
	connect(filePushBtn,SIGNAL(clicked()),this,
				SLOT(doPushBtn()));
	connect(fontPushBtn,SIGNAL(clicked()),this,
				SLOT(doPushBtn()));
	connect(inputPushBtn,SIGNAL(clicked()),this,
				SLOT(doPushBtn()));
	connect(pagePushBtn,SIGNAL(clicked()),this,
				SLOT(doPushBtn()));
	connect(progressPushBtn,SIGNAL(clicked()),this,
				SLOT(doPushBtn()));
	connect(printPushBtn,SIGNAL(clicked()),this,
				SLOT(doPushBtn()));
	setWindowTitle(tr("内建对话框"));
	resize(400,300);
}
void CBuiltinDlg::doPushBtn()
{
	QPushButton* btn=qobject_cast(QPushButton*)(sender());
	if(btn==colorPushBtn)
	{
		
	}
}
