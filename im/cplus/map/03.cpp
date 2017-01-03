//用数据方式插入数据
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void){
	map<int,string> mapStudent;
	mapStudent[1] = "one";
	mapStudent[2] = "two";
	mapStudent[3] = "three";
	mapStudent[4] = "four";
	for(auto i : mapStudent){
		cout << i.first << ',' << i.second << endl;
	}
	return 0;
}
