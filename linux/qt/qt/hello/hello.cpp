#include<QApplication>
#include<QWidget>
#include<QLabel>
#include<QTextCodec>
int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
	QWidget* pWidget=new QWidget;
	QLabel label(pWidget);
	label.setText(QObject::tr("同一个世界同一个梦想"));
	pWidget->show();
	return app.exec();
}
