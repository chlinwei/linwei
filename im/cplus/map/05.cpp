#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(void){
	map<int,string> mapStudent;
	mapStudent[1] = "one";
	mapStudent[1] = "two";//数组方式插入是后面的数据覆盖前面的数据
	mapStudent[3] = "three";
	for(auto i : mapStudent){
		cout << i.first << ',' << i.second << endl;
	}
	return 0;
}
