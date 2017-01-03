#include "CalculatorDialog.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc,char* argv[])
{
	QTextCodec::setCodecForTr(
		QTextCodec::codecForName("utf-8"));
	QApplication app(argc,argv);
	CalculatorDialog dialog;
	dialog.show();
	return app.exec();
}
