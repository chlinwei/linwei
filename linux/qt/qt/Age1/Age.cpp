#include<QGuiApplication>
#include<QSlider>
#include<QSpinBox>
int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	QWidget *window=new QWidget;
	window->setWindowTitle("Enter your age");
	QSpinBox* spinBox=new QSpinBox();//微调框
	QSlider* slider=new QSlider(Qt::Horizontal);//滑块水平的
	spinBox->setRange(0,130);
	slider->setRange(0,130);
	QObject::connect(spinBox,SIGNAL(valueChanged(int)),
			slider,SLOT(setValue(int)));
	QObject::connect(slider,SIGNAL(valueChanged(int)),
			spinBox,SLOT(setValue(int)));
	spinBox->setValue(30);
	QHBoxLayout* layout=new QHBoxLayout;//布局管理器
	//在水平方向上排列窗口部件
	layout->addWidget(spinBox);
	layout->addWidget(slider);
	window->setLayout(layout);
	window->show();
	return app.exec();	
}
