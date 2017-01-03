//mapStudent.insert(map<int,string)::value_type(1,"one"));
//mapStudent.insert(map<int,string)::value_type(1,"two"));
//mapStudent是个map,这样第二条语句将会失效
//pair<map<int,string>::iterator,bool> insert_pair;
//第一个变量返回的是一个map的迭代器,如果插入成功bool为true,否则false
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(void){
	map<int,string> mapStudent;
	pair<map<int,string>::iterator,bool> insert_pair;
	insert_pair = mapStudent.insert(pair<int,string>(1,"one"));
	if(insert_pair.second == true){
		cout << "insert sucessfully" << endl;
	}
	else{
		cout << "insert failed" << endl;
	}
	insert_pair = mapStudent.insert(pair<int,string>(1,"one"));
	if(insert_pair.second == true){
		cout << "insert sucessfully" << endl;
	}
	else{
		cout << "insert failed" << endl;
	}

	return 0;
}
