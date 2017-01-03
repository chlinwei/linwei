#include <QApplication>
#include <QTextCodec>
#include <QLabel>
#include <QPushButton>

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	QTextCodec::setCodecForTr(
		QTextCodec::codecForName("utf-8"));
	QLabel lab(QObject::tr("点击按钮关闭我！"));
	QPushButton btn(QObject::tr("关闭"));
	/*把关闭按钮时信号clicked和
	  标签槽函数close连接起来*/
	QObject::connect(&btn,SIGNAL(clicked(void)),
			&lab,SLOT(close(void)));
	/*练习:增加一个“退出”按钮，点击时
	  关闭整个应用程序*/
	QPushButton btn2(QObject::tr("退出"));
	QObject::connect(&btn2,SIGNAL(clicked(void)),
			&app,SLOT(quit(void)));

	lab.show();
	btn.show();
	btn2.show();

	return app.exec();
}

