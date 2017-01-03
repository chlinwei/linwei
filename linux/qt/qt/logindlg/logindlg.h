#ifndef _LOGINDLG_H
#define _LOGINDLG_H
#include<QtGui>
//class QLineEdit;
class CLoginDlg:public QDialog
{
	Q_OBJECT
	public:
		CLoginDlg(QWidget* =NULL);
		public slots:
			virtual void accept();
	private:
		QLineEdit* usrLineEdit;
		QLineEdit* pwdLineEdit;
};
#endif
