//1.map用insert函数插入pair数据
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(void){
	map<int,string> mapStudent;
	//这里如果 
	mapStudent.insert(pair<int,string>(1,"one"));
	mapStudent.insert(pair<int,string>(2,"two"));//如果改为1则这条语句不会生效
	mapStudent.insert(pair<int,string>(3,"three"));
	mapStudent.insert(pair<int,string>(4,"four"));
	for(auto i : mapStudent){
		cout << i.first << ',' << i.second << endl;
	}
	return 0;
}
