#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	//向文件写入
	ofstream ofs("file.txt");
	ofs << 1234 << ' ' << 56.879 << ' '
		<< "helloworld" << endl;
	ofs.close();
	//从文件读取
	ifstream ifs("file.txt");
	int i;
	double d;
	string s;
	ifs >> i >> d >> s;
	cout << i << ' ' << d << ' ' << s << endl;
	ifs.close();
	return 0;
}
