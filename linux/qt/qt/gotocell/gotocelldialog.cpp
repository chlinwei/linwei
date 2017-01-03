#include<QtGui>
#include"gotocelldialog.h"
GoToCellDialog::GoToCellDialog(QWidget* parent)
	:QDialog(parent)
{
	setupUi(this);
	QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
	//设置检验器来限制输入的范围
	lineEdit->setValidator(new QRegExpValidator(regExp,this));
	connect(OkButton,SIGNAL(clicked()),this,SLOT(accept()));
	connect(cancelButton_,SIGNAL(clicked()),this,SLOT(reject()));
}
void GoToCellDialog::on_lineEdit_textChanged()
{
	OkButton->setEnabled(lineEdit->hasAcceptableInput());
}
