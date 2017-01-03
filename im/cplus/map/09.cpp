#include <map>
#include <iostream>
#include <string>
using namespace std;
int main(void){
	map<int,string> mapStudent;
	mapStudent[1] = "student1";
	mapStudent[2] = "student2";
	mapStudent[3] = "student3";
	map<int,string> :: iterator iter;
	//lower_bound返回的是对应的迭代器
	//upper_bound返回的是对应的迭代器的下一个
	iter = mapStudent.lower_bound(2);
	cout << iter->second << endl;
	iter = mapStudent.upper_bound(2);
	cout << iter->second << endl;
	return 0;
}
