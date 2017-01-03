#ifdef _MAINWINDOW_H
#define _MAINWINDOW_H
#include <QMainWindow>
class MainWindow : public QMainWindow{
	Q_OBJECT
	public:
		MainWindow(QWidget* parent = 0);
		~MainWindow();
	private:
		void open();
		QAction* openAction;
};
#endif


