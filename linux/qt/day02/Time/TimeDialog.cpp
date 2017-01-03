#include <QtGui>
#include "TimeDialog.h"

TimeDialog::TimeDialog
		(QWidget* parent/*=NULL*/)
						:QDialog(parent){
	setWindowTitle(tr("时间"));
	m_labTime = new QLabel;
	//设置label显示效果
	m_labTime->setFrameStyle(
			QFrame::Panel|QFrame::Sunken);
	//设置居中
	m_labTime->setAlignment(
			Qt::AlignHCenter|Qt::AlignVCenter);
	QPushButton* btnTime = 
		new QPushButton(tr("当前系统时间"));
	//创建垂直布局器
	QVBoxLayout* lay= new QVBoxLayout;
	lay->addWidget(m_labTime);
	lay->addWidget(btnTime);
	setLayout(lay);
	//连接信号和自定义槽
	connect(btnTime,SIGNAL(clicked(void)),
			this,SLOT(timeClicked(void)));
	//连接自定义信号和槽
	connect(this,
		SIGNAL(setText(const QString&)),
		m_labTime,
		SLOT(setText(const QString&)));
}
void TimeDialog::timeClicked(void)
{	
	/*
	m_labTime->setText(
		QTime::currentTime().
			toString("hh:mm:ss"));*/
	emit setText(QTime::currentTime().
					toString("hh:mm:ss"));
}








