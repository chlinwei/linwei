//数据的查找
//1.用count函数来判断关键字是否出现,其缺点是无法定位数据出现的位置
//由于map的特性,一对一的映射关系,就决定了count函数的返回值只有两个0,1出现的情况,当然是1
#include <map>
#include <iostream>
#include <string>
using namespace std; 
int main(void){
	map<int,string> mapStudent;
   mapStudent.insert(pair<int,string>(1,"one"))	;
   mapStudent.insert(pair<int,string>(2,"two"))	;
   mapStudent.insert(pair<int,string>(3,"three"));
   map<int,string>::iterator iter;
   iter = mapStudent.find(1);//返回关键字1对象的迭代器
   if(iter != mapStudent.end()){
	   cout << "find,the value is " << iter->second << endl;
   }
   else {
	   cout << "do not find" << endl;
   }
	return 0;
}
