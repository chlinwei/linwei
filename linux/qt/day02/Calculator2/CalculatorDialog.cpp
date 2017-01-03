#include "CalculatorDialog.h"
#include <QtGui>

CalculatorDialog::CalculatorDialog(
	QWidget* parent/*=NULL*/):QDialog(parent){
	setupUi(this);
	//安装验证器
	m_editX->setValidator(
			new QDoubleValidator(this));
	m_editY->setValidator(
			new QDoubleValidator(this));
	//连接信号和槽函数
	connect(m_editX,
		SIGNAL(textChanged(const QString&)),
		this,SLOT(enableCalcButton()));
	connect(m_editY,
		SIGNAL(textChanged(const QString&)),
		this,SLOT(enableCalcButton()));
	connect(m_btnCalc,SIGNAL(clicked(void)),
		this,SLOT(calClicked(void)));
};
void CalculatorDialog::enableCalcButton(void){
	bool bXOk,bYOk;
	m_editX->text().toDouble(&bXOk);
	m_editY->text().toDouble(&bYOk);
	if(bXOk && bYOk){
		m_btnCalc->setEnabled(true);//使能按钮
	}
	else{
		m_btnCalc->setEnabled(false);
	}
	//如果等号按钮被禁用，则清空Z编辑框
	if(!m_btnCalc->isEnabled()){
		m_editZ->setText("");
	}
}
void CalculatorDialog::calClicked(void){
	double res = m_editX->text().toDouble() +
				m_editY->text().toDouble();
	//将浮点数转成字符串,紧凑格式,15位有效数字
	QString string = 
		QString::number(res,'g',15);
	//显示计算结果
	m_editZ->setText(string);
}




















