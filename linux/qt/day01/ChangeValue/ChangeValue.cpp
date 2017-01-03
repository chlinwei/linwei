#include <QApplication>
#include <QDialog>
#include <QSlider>
#include <QSpinBox>

int main(int argc,char** argv)
{
	QApplication app(argc,argv);
	QDialog dlg;//创建父窗口
	dlg.resize(200,100);
	//创建水平滑块对象并停靠父窗口上
	QSlider slider(Qt::Horizontal,&dlg);
	slider.move(20,20);//矩形的左上角为矩形的中心点,
	//窗口的左上角为起点
	slider.setRange(0,100);//设置slider的范围值
	slider.setPageStep(10);//设置按下pageup和pagedown
	//时数值增加或减少的多少
	slider.setValue(20);//设置初值

	//创建微调框对象,停靠在父窗口
	QSpinBox spin(&dlg);
	spin.move(120,20);
	spin.setRange(0,100);
	spin.setValue(20);
	//滑块位置改变，微调框值一起改变
	QObject::connect(&slider,
		SIGNAL(valueChanged(int)),
		&spin,SLOT(setValue(int)));
	//微调框值改变，滑块跟着一起改变
	QObject::connect(&spin,
		SIGNAL(valueChanged(int)),
		&slider,SLOT(setValue(int)));
	dlg.show();
	return app.exec();
}





