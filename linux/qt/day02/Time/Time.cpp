#include <QTextCodec>
#include <QApplication>
#include "TimeDialog.h"

int main(int argc,char* argv[])
{
	QTextCodec::setCodecForTr(
		QTextCodec::codecForName("utf-8"));
	QApplication app(argc,argv);
	TimeDialog dialog;
	dialog.show();
	return app.exec();

}
