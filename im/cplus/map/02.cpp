//用insert函数插入value_type数据
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(void){
	map<int,string> mapStudent;
	mapStudent.insert(map<int,string>::value_type(1,"one"));
	mapStudent.insert(map<int,string>::value_type(2,"two"));
	mapStudent.insert(map<int,string>::value_type(3,"three"));
	mapStudent.insert(map<int,string>::value_type(4,"four"));
	mapStudent.insert(map<int,string>::value_type(5,"five"));
	for(auto i : mapStudent){
		cout << i.first << "," << i.second << endl;
	}
	return 0;
}
