#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main(void){
	string str = "I am a boy";
	istringstream is(str);
	//istringstream的构造函数如下
	//istringstream::istringstream(string str);
	string s;
	while(is >> s){
		cout << s << endl;
	}
	return 0;
}
