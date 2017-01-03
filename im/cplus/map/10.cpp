#include <map>
#include <iostream>
#include <string>
using namespace std;
int main(void){
	map<int,string> mapStudent;
	mapStudent[1] = "one";
	mapStudent[2] = "two";
	mapStudent[3] = "three";
	pair<map<int,string>::iterator,map<int,string>::iterator> mapPair;
	mapPair = mapStudent.equal_range(2);
	//equal_range函数返回一个pair,pair的第一个参数是
	//lower_bound返回的迭代器,第二个参数是uppper_bound返回的迭代器
	//如果这两个迭代器相等,则说明map中不出现这个关键字
	if(mapPair.first == mapPair.second){
		cout << "do not find" << endl;
	}
	else {
		cout << "find" << ',' << mapPair.first->first << endl;
	}
	return 0;
}
