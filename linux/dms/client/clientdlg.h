// 声明客户机对话框类
#ifndef _CLIENTDLG_H
#define _CLIENTDLG_H
#include <QDialog>
#include "workthread.h"
class QTextBrowser;
// 客户机对话框
class ClientDlg : public QDialog {
	Q_OBJECT
public:
	ClientDlg (void);
private slots:
	void onStart (void);
	void onUpdate (QString const& text);
private:
	QTextBrowser* m_browser;
	WorkThread m_work;
};
#endif // _CLIENTDLG_H
