/********************************************************************************
** Form generated from reading UI file 'gotocelldialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOTOCELLDIALOG_H
#define UI_GOTOCELLDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GoToCellDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *OkButton;
    QPushButton *cancelButton_;

    void setupUi(QWidget *GoToCellDialog)
    {
        if (GoToCellDialog->objectName().isEmpty())
            GoToCellDialog->setObjectName(QString::fromUtf8("GoToCellDialog"));
		//fromUtf8(const string& str,int size=-1)
        GoToCellDialog->resize(475, 162);
        widget = new QWidget(GoToCellDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 20, 252, 66));
		//void setGeometry(const QRect& rect);
		//void setGeometry(int x,int y,int w,int h);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        OkButton = new QPushButton(widget);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));
        OkButton->setEnabled(false);

        horizontalLayout_2->addWidget(OkButton);

        cancelButton_ = new QPushButton(widget);
        cancelButton_->setObjectName(QString::fromUtf8("cancelButton_"));

        horizontalLayout_2->addWidget(cancelButton_);


        verticalLayout->addLayout(horizontalLayout_2);

        OkButton->raise();
        cancelButton_->raise();
        label->raise();
        lineEdit->raise();
        label->raise();
        label->raise();
#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lineEdit, OkButton);
        QWidget::setTabOrder(OkButton, cancelButton_);

        retranslateUi(GoToCellDialog);

        QMetaObject::connectSlotsByName(GoToCellDialog);
    } // setupUi

    void retranslateUi(QWidget *GoToCellDialog)
    {
        GoToCellDialog->setWindowTitle(QApplication::translate("GoToCellDialog", "GOToCell", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GoToCellDialog", "&Cell Location", 0, QApplication::UnicodeUTF8));
        OkButton->setText(QApplication::translate("GoToCellDialog", "PushButton", 0, QApplication::UnicodeUTF8));
        cancelButton_->setText(QApplication::translate("GoToCellDialog", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GoToCellDialog: public Ui_GoToCellDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOTOCELLDIALOG_H
