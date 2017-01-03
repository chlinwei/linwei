#include <QApplication>
#include <QLabel>
#include <QTextCodec>
#include <QObject>
int main(int argc,char* argv[])
{
	//构造qt应用程序对象
	QApplication app(argc,argv);
	//1 创建可以处理UTF-8字符的编码器
	QTextCodec* coder = 
		QTextCodec::codecForName("utf-8");
	//QTexCodec* codecForName(const char *name);//设置utf8编码器
	//void setCodecForTr(QTextCodec *c)//设置解码器
	//2 设置编码器
	QTextCodec::setCodecForTr(coder);
	//3 根据设置进行翻译
	//QObject::tr将外部编码转换成内部utf-16内部编码
	QLabel label(QObject::tr("你好，QT！"));
	//显示标签对象
	label.show();
	//让进程进入事件循环
	return app.exec();
}
