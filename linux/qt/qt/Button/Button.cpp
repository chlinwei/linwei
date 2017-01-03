#include<QApplication>
#include<QPushButton>
#include<QFont>
int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	QPushButton quit("Quit",0);
	quit.resize(75,30);
	//resize是QWidget里的
	//void resize(int w,int h);
	quit.setFont(QFont("Times",18,QFont::Bold));
	//setFont(const Font&)
	//QFont(const QString& family,int pointSize=-1,
	//int weight=-1,bool italic=false);
	//family:字体的名称
	//pointSize:字体的点大小
	//weight:字体是否为粗体
	//italic:字体是否为斜体
	QObject::connect(&quit,SIGNAL(clicked()),&app,SLOT(quit()));
	quit.show();
	return app.exec();
}
