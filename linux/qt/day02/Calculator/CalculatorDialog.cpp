#include "CalculatorDialog.h"
#include <QtGui>

CalculatorDialog::CalculatorDialog(
	QWidget* parent/*=NULL*/):QDialog(parent){
	//设置窗口的标题
	setWindowTitle(tr("计算器"));
	//创建X编辑框输入组件
	m_editX = new QLineEdit(this);
	//设置右对齐
	m_editX->setAlignment(Qt::AlignRight);
	//安装验证器
	m_editX->setValidator(
			new QDoubleValidator(this));
	//void setValidator(const QValidator* v);
	//QDoubleValidator
	//创建Y编辑框
	m_editY = new QLineEdit(this);
	m_editY->setAlignment(Qt::AlignRight);
	m_editY->setValidator(
			new QDoubleValidator(this));
	//创建等号按钮
	m_btnCalc = new QPushButton("=",this);
	m_btnCalc->setEnabled(false);//禁用
	//创建Z编辑框
	m_editZ = new QLineEdit(this);
	m_editZ->setAlignment(Qt::AlignRight);
	m_editZ->setReadOnly(true);//只读
	//创建布局器
	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(m_editX);
	layout->addWidget(new QLabel("+"));
	layout->addWidget(m_editY);
	layout->addWidget(m_btnCalc);
	layout->addWidget(m_editZ);
	//设置布局器
	setLayout(layout);
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
	//double toDouble(bool* ok=0)//成功ok=true失败ok=0
	
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




















