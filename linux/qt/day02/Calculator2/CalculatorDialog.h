#ifndef __CALCULATORDIALIG_H
#define __CALCULATORDIALIG_H
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include "ui_CalculatorDialog.h"

class CalculatorDialog:public QDialog,
	public Ui::CalculatorDialog{
	Q_OBJECT
public:
	CalculatorDialog(QWidget* parent = NULL);
private slots:
	void enableCalcButton(void);
	void calClicked(void);
};

#endif//__CALCULATORDIALIG_H
