/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created: Mon Jan 18 16:16:35 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *m_labUsername;
    QLineEdit *m_editUsername;
    QLabel *label;
    QLineEdit *m_editPassword;
    QDialogButtonBox *m_btnBox;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(230, 170);
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_labUsername = new QLabel(LoginDialog);
        m_labUsername->setObjectName(QString::fromUtf8("m_labUsername"));
        QFont font;
        font.setPointSize(16);
        m_labUsername->setFont(font);
        m_labUsername->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(m_labUsername, 0, 0, 1, 1);

        m_editUsername = new QLineEdit(LoginDialog);
        m_editUsername->setObjectName(QString::fromUtf8("m_editUsername"));

        gridLayout->addWidget(m_editUsername, 0, 1, 1, 1);

        label = new QLabel(LoginDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        m_editPassword = new QLineEdit(LoginDialog);
        m_editPassword->setObjectName(QString::fromUtf8("m_editPassword"));
        m_editPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(m_editPassword, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        m_btnBox = new QDialogButtonBox(LoginDialog);
        m_btnBox->setObjectName(QString::fromUtf8("m_btnBox"));
        m_btnBox->setLayoutDirection(Qt::RightToLeft);
        m_btnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        m_btnBox->setCenterButtons(true);

        verticalLayout->addWidget(m_btnBox);

        verticalSpacer_2 = new QSpacerItem(20, 19, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\347\231\273\351\231\206", 0, QApplication::UnicodeUTF8));
        m_labUsername->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
