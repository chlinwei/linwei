//map数据的清空用clear,判断是否为空empty()
//map中数据的删除

#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void){
	map<int,string> mapStudent;
	mapStudent.insert(pair<int,string>(1,"one"));
	mapStudent.insert(pair<int,string>(2,"two"));
	mapStudent.insert(pair<int,string>(3,"three"));
	map<int,string> :: iterator iter;
	iter = mapStudent.find(5);
	if(iter){
	}
	mapStudent.erase(iter);//删除了关键字1
	for(auto i : mapStudent){
		cout << i.first << ',' << i.second << endl;
	}
	return 0;
}
