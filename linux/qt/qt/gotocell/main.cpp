#include<QApplication>
#include<QDialog>
#include"gotocelldialog.h"
//qmake可以自动检测到用户界面文件gotocelldialog.ui
//并且生成适当的makefile规则来调用Qt的用户界面编译器uic(user interface 
//compiler)uic 工具会将gotocelldialog.ui文件转化成C++并且将
//转换结果存储在ui_gotocelldialog.h文件中
int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	GoToCellDialog* dialog=new GoToCellDialog;
	dialog->show();
	return app.exec();
}
