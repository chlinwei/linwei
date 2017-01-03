#ifndef _GOTOCELLDIALOG
#define _GOTOCELLDIALOG
//#include<QDialog>
//#include<QtWidgets>
#include"ui_gotocelldialog.h"
class GoToCellDialog:public QDialog,public Ui::GoToCellDialog
{
	Q_OBJECT
		public:
		GoToCellDialog(QWidget* parent=0);
		private slots:
			void on_lineEdit_textChanged();
};
#endif
