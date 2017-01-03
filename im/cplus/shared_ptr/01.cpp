#include <memory>
#include <iostream>
#include <map>
using namespace std;
int main(void){
	shared_ptr<map<int,string>> ptr(new map<int,string>{{1,"one"}});
	//map<int,string>是个类类型的类型,所以初始化类用花括号,
	//map类类型的成员是pair也是个类类型,初始化pair也用花括号
	//所以有两个花括号
	ptr->insert({2,"two"});
	ptr->insert(pair<int,string>(3,"three"));
	ptr->insert(map<int,string>::value_type(4,"four"));
	for(auto i : *ptr){//这里的i为pair类型的 pait<int,string>
		cout << i.first << ',' << i.second << endl;
	}

	return 0;
}
