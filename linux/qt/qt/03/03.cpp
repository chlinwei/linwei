#include<QApplication>
#include<QPushButton>
#include<QFont>
#include<QVBoxLayout>
int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	QVBox box;
	box.resize(200,100);
	QPushButton quit("Quit",&box);
	quit.setFont(QFont("Times",18,QFont::Bold));
	QObject::connect(&quit,SIGNAL(clicked()),
			&app,SLOT(quit()));
	box.show();
	return app.exec();
}
