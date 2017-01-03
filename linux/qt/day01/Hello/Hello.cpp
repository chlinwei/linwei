#include <QApplication>
#include <QLabel>

int main(int argc,char* argv[])
{
	//构造qt应用程序对象
	QApplication app(argc,argv);
	//构造标签对象
	QLabel label("Hello Qt!");
	//显示标签对象
	label.show();
	//让进程进入事件循环
	return app.exec();
}
