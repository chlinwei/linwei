#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;

int main(void)
{
	int i = 100;
	double d = 56.78;
	char c = 'T';
	char s[]="hello world!";
	/*
	char buf[1024]={0};
	sprintf(buf,"%d %g %c %s",i,d,c,s);
	cout << buf << endl;*/
	ostringstream oss;
	oss << i << ' ' << d << ' '<< c <<' ' << s;
	string str = oss.str();
	cout << str << endl;
	return 0;
}



