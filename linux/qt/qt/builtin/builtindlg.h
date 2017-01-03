#ifndef _BUILTINDLG_H
#define _BUILTINDLG_H
#include<QtGui>
class CBuiltinDlg: public QDialog
{
	Q_OBJECT
		public:
		CBuiltinDlg(QWidget* =0);
		virtual ~CBuiltinDlg(){}
		private:
		QTextEdit* displayTextEdit;
		QPushButton* colorPushBtn;
		QPushButton* errorPushBtn;
		QPushButton* filePushBtn;
		QPushButton* fontPushBtn;
		QPushButton* inputPushBtn;
		QPushButton* pagePushBtn;
		QPushButton* progressPushBtn;
		QPushButton* printPushBtn;
		private slots:
			void doPushBtn();
};
#endif
