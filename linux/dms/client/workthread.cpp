// 实现工作线程类
#include "workthread.h"
#include "logreader.h"
#include "socketsender.h"
#include "client.h"
void WorkThread::run (void) {
	/*
	sleep (1);
	update ("Hello, DMS !");
	sleep (1);
	update ("Hello, DMS !");
	sleep (1);
	update ("Hello, DMS !");
	sleep (1);
	update ("Hello, DMS !");
	sleep (1);
	update ("Hello, DMS !");
	*/
	try {
		LogReader reader ("./wtmpx",
			"./logins.dat");
		SocketSender sender ("./fail.dat",
			8888, "172.164.6.10", this);
		Client client (reader, sender);
		client.dataMine ();
	}
	catch (exception& ex) {
		cout << ex.what () << endl;
	}
}
void WorkThread::update (string const& text) {
	update (QString (text.c_str ()));
}
