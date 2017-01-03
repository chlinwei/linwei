#include <QApplication>
#include <QTextCodec>
#include "LoginDialog.h"
#include <QTranslator>
int main(int argc,char *argv[])
{
	QApplication app(argc,argv);
	QTextCodec::setCodecForTr(
		QTextCodec::codecForName("utf-8"));
	//设置翻译器
	//1创建翻译器对象
	QTranslator tr;
	//2加载翻译器
	//QLocale::system();//获取QLocale 对象
	tr.load("qt_"+QLocale::system().name(),
			"/usr/share/qt4/translations");
	/*tr.load("qt_zh_CN.qm",
			"/usr/share/qt4/translations");*/
	//3安装翻译器到应用程序
	app.installTranslator(&tr);

	LoginDialog dialog;
	dialog.show();
	return app.exec();
}
