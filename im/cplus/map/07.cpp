//数据的遍历
//2.用数组的方法
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(void){
	map<int,string> mapStudent;
	mapStudent.insert(pair<int,string>(1,"one"));
	mapStudent.insert(pair<int,string>(2,"two"));
	mapStudent.insert(pair<int,string>(3,"three"));
	//这里注意是从1开始,<=和vector不同
	for(int i = 1;i <= mapStudent.size();++i ){
		cout << mapStudent[i] << ',';
	}
	return 0;
}
