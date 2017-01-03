#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	ofstream ofs("123.txt");
	char wbuf[100]="jiangguiliang94@sina.com";
	ofs.write(wbuf,sizeof(wbuf));
	ofs.close();

	ifstream ifs("123.txt");
	char rbuf[100]={0};
	ifs.read(rbuf,sizeof(rbuf));
	cout << rbuf << endl;
	ifs.close();
	return 0;
}





