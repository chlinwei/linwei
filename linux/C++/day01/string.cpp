#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
	string s = "hello";
	cout << s << endl;
	//字符串的连接
	s += "world";
	cout << s << endl;
	//字符串的拷贝
	string s2 = s;
	cout << "s = " << s << endl;
	cout << "s2 = " << s2 << endl;
	//取出字符串某个字符
	cout << s[0] << ',' << s[5] << endl;
	string s3 = "12345678";
	//字符串的交换
	swap(s3,s2);
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	//字符串比较
	cout << (s == s2) << endl;
	cout << (s == s3) << endl;//1
	cout << (s > s2) << endl;//1
	//字符串长度
	cout << s.length() << endl;//10
	//转化为C风格char*形式的字符串
	cout << strlen(s.c_str()) << endl;//10
	return 0;
}



