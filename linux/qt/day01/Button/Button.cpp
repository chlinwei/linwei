#include <QApplication>
#include <QTextCodec>
#include <QPushButton>

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	QTextCodec::setCodecForTr(
		QTextCodec::codecForName("utf-8"));
	/*创建按钮对象*/
	QPushButton btn(QObject::tr("按我！"));
	btn.show();
	return app.exec();
}
