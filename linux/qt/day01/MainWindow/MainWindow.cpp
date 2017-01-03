#include <QTextCodec>
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	QTextCodec::setCodecForTr(
		QTextCodec::codecForName("utf-8"));
	//创建父窗口
	QMainWindow wnd;
	wnd.resize(210,110);
	QLabel* lab = new QLabel(
		QObject::tr("我是标签子窗口:)"),
		&wnd);
	lab->move(30,20);
	lab->resize(150,20);
	QPushButton* btn = new QPushButton(
		QObject::tr("退出"),&wnd);
	btn->move(55,60);
	QObject::connect(btn,
		SIGNAL(clicked(void)),
		&wnd,SLOT(close(void)));
	wnd.show();
	return app.exec();
}






