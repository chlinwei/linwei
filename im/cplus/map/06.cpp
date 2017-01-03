//数据的遍历
//1.取反向迭代器
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(void){
	map<int,string> mapStudent;
	mapStudent.insert(pair<int,string>(1,"one"));
	mapStudent.insert(pair<int,string>(2,"two"));
	mapStudent.insert(pair<int,string>(3,"three"));
	map<int,string>::reverse_iterator iter;
	for(iter = mapStudent.rbegin() ; iter != mapStudent.rend();++iter){
		cout << iter->first << ',' << iter->second << endl;
	}
	return 0;
}
