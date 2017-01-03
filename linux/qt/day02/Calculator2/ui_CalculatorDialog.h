/********************************************************************************
** Form generated from reading UI file 'CalculatorDialog.ui'
**
** Created: Mon Jan 18 15:17:37 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORDIALOG_H
#define UI_CALCULATORDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CalculatorDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *m_editX;
    QLabel *m_labOp;
    QLineEdit *m_editY;
    QPushButton *m_btnCalc;
    QLineEdit *m_editZ;

    void setupUi(QDialog *CalculatorDialog)
    {
        if (CalculatorDialog->objectName().isEmpty())
            CalculatorDialog->setObjectName(QString::fromUtf8("CalculatorDialog"));
        CalculatorDialog->setEnabled(true);
        CalculatorDialog->resize(472, 50);
        horizontalLayout = new QHBoxLayout(CalculatorDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_editX = new QLineEdit(CalculatorDialog);
        m_editX->setObjectName(QString::fromUtf8("m_editX"));
        m_editX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(m_editX);

        m_labOp = new QLabel(CalculatorDialog);
        m_labOp->setObjectName(QString::fromUtf8("m_labOp"));
        QFont font;
        font.setPointSize(18);
        m_labOp->setFont(font);
        m_labOp->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(m_labOp);

        m_editY = new QLineEdit(CalculatorDialog);
        m_editY->setObjectName(QString::fromUtf8("m_editY"));
        m_editY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(m_editY);

        m_btnCalc = new QPushButton(CalculatorDialog);
        m_btnCalc->setObjectName(QString::fromUtf8("m_btnCalc"));
        m_btnCalc->setEnabled(false);
        QFont font1;
        font1.setPointSize(12);
        m_btnCalc->setFont(font1);

        horizontalLayout->addWidget(m_btnCalc);

        m_editZ = new QLineEdit(CalculatorDialog);
        m_editZ->setObjectName(QString::fromUtf8("m_editZ"));
        m_editZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        m_editZ->setReadOnly(true);

        horizontalLayout->addWidget(m_editZ);

        QWidget::setTabOrder(m_editX, m_editY);
        QWidget::setTabOrder(m_editY, m_btnCalc);
        QWidget::setTabOrder(m_btnCalc, m_editZ);

        retranslateUi(CalculatorDialog);

        QMetaObject::connectSlotsByName(CalculatorDialog);
    } // setupUi

    void retranslateUi(QDialog *CalculatorDialog)
    {
        CalculatorDialog->setWindowTitle(QApplication::translate("CalculatorDialog", "\350\256\241\347\256\227\345\231\250", 0, QApplication::UnicodeUTF8));
        m_labOp->setText(QApplication::translate("CalculatorDialog", "+", 0, QApplication::UnicodeUTF8));
        m_btnCalc->setText(QApplication::translate("CalculatorDialog", "=", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CalculatorDialog: public Ui_CalculatorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORDIALOG_H
