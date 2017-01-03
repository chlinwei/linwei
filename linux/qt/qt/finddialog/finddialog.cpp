#include<QtGui>
#include"finddialog.h"

FindDialog::FindDialog(QWidget* parent)
		:QDialog(parent)
		 //构造函数
{
	label=new QLabel(tr("Find &what:"));
	lineEdit=new QLineEdit;
	label->setBuddy(lineEdit);
	//所谓伙伴就是一个窗口部件它可以在按下
	//标签的快捷键时来接搜焦点
	//所以ALT+W(该标签的快捷键)时,焦点就会
	//移动到这个行编辑器上(该标签的伙伴上)
	caseCheckBox=new QCheckBox(tr("Match& case"));//&可以用来控制焦点
	backwardCheckBox=new QCheckBox(tr("Search& backward"));
	findButton=new QPushButton(tr("&Find"));
	findButton->setDefault(true);
	//让find按钮成为对话框的默认按钮
	//默认按钮就是当用户按下Enter键时能够
	//按下对应的按钮
	findButton->setEnabled(false);//禁止了find按钮
	closeButton=new QPushButton(tr("Close"));
	connect(lineEdit,SIGNAL(textChanged(const QString&)),this,SLOT(enableFindButton(const QString&)));
	//当编辑器中的文本发生变化,就会调用私有槽
	connect(findButton,SIGNAL(clicked()),this,SLOT(findClicked()));
	//当用户点击Find按钮,就会调用findClicked()私有槽
	connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
	//当用户点击close按钮,就会调用调用close()函数关闭
	//对话框
	QHBoxLayout* topLeftLayout=new QHBoxLayout;
	//水平的布局器
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(lineEdit);

	QVBoxLayout* leftLayout=new QVBoxLayout;
	//垂直的布局器
	leftLayout->addLayout(topLeftLayout);
	leftLayout->addWidget(caseCheckBox);
	leftLayout->addWidget(backwardCheckBox);

	QVBoxLayout* rightLayout=new QVBoxLayout;
	rightLayout->addWidget(findButton);
	rightLayout->addWidget(closeButton);
	rightLayout->addStretch();
	//弹簧

	QHBoxLayout* mainLayout=new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);
	setWindowTitle(tr("Find"));
	setFixedHeight(sizeHint().height());
    //返回窗口理想尺寸大小
}

void FindDialog::findClicked()
{
	QString text=lineEdit->text();
	Qt::CaseSensitivity cs=caseCheckBox->isChecked() ? Qt::CaseSensitive: Qt::CaseInsensitive;
	if(backwardCheckBox->isChecked())
	{
		emit findPreious(text,cs);
	}
	else
	{
		emit findNext(text,cs);
	}
}
void FindDialog::enableFindButton(const QString &text)
{
	//只要用户改变了行编译器中的文本
	//就会调用enableFindButton()槽
	findButton->setEnabled(!text.isEmpty());
}

