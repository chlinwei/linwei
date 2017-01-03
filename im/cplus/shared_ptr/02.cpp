#include <map>
#include <memory>
#include <iostream>
//make_shared 此函数在动态内存中分配一个对象并且初始化它,返回
//指向此对象的shared_ptr
using namespace std;

int main(void){
	map<int,string> mapStudent {{1,"one"}};
	shared_ptr<map<int,string>> ptr = make_shared<map<int,string>>(mapStudent);
	shared_ptr<map<int,string>> ptr2 = make_shared<map<int,string>>(map<int,string>{{1,"one"}});
	//make_shared是模板函数
	for(auto i : *ptr2){
		cout << i.second << endl;
	}
	return 0;

}
