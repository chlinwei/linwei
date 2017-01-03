#ifndef __CALCULATORDIALIG_H
#define __CALCULATORDIALIG_H
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
class CalculatorDialog:public QDialog{
	Q_OBJECT
public:
	CalculatorDialog(QWidget* parent = NULL);
private:
	QLineEdit* m_editX;
	QLineEdit* m_editY;
	QPushButton* m_btnCalc;
	QLineEdit* m_editZ;
private slots:
	//处理编辑框文本改变信号 的槽函数
	void enableCalcButton(void);
	void calClicked(void);
};

#endif//__CALCULATORDIALIG_H
