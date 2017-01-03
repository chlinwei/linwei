#include "CalculatorDialog.h"
#include "ui_CalculatorDialog.h"

CalculatorDialog::CalculatorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalculatorDialog)
{
    ui->setupUi(this);
}

CalculatorDialog::~CalculatorDialog()
{
    delete ui;
}
