// 实现客户机对话框类
#include <QtGui>
#include "clientdlg.h"
ClientDlg::ClientDlg (void) {
	QTextCodec::setCodecForTr (
		QTextCodec::codecForName ("utf-8"));
	setWindowTitle (tr ("DMS数据采集客户机"));
	resize (520, 520);
	m_browser = new QTextBrowser;
	m_browser->setFrameStyle (QFrame::Panel |
		QFrame::Sunken);
	QPushButton* btnStart = new QPushButton (
		tr ("开始"));
	connect (btnStart, SIGNAL (
		clicked (void)), this, SLOT (
		onStart (void)));
	QPushButton* btnClose = new QPushButton (
		tr ("关闭"));
	connect (btnClose, SIGNAL (
		clicked (void)), this, SLOT (
		close (void)));
	QHBoxLayout* layHor = new QHBoxLayout;
	layHor->addStretch ();
	layHor->addWidget (btnStart);
	layHor->addWidget (btnClose);
	layHor->addStretch ();
	QVBoxLayout* layVer = new QVBoxLayout;
	layVer->addWidget (m_browser);
	layVer->addLayout (layHor);
	setLayout (layVer);
	connect (&m_work, SIGNAL (
		update (QString const&)), this, SLOT (
		onUpdate (QString const&)));
}
void ClientDlg::onStart (void) {
	/*
	sleep (1);
	m_browser->append ("Hello, DMS !");
	sleep (1);
	m_browser->append ("Hello, DMS !");
	sleep (1);
	m_browser->append ("Hello, DMS !");
	sleep (1);
	m_browser->append ("Hello, DMS !");
	sleep (1);
	m_browser->append ("Hello, DMS !");
	*/
	m_work.start ();
}
void ClientDlg::onUpdate (
	QString const& text) {
	m_browser->append (text);
}
