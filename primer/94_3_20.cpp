//输入一组整数,存入vector对象
//1)将相邻整数和输出出来
//2)先输出第1个和最后1个元素的和,接着输出第2个元素和倒数第2个元素的和,以次类推
#include <vector>
#include <iostream>
using namespace std;
int main(void){
	string str;
	cout << "请输入一组整数:";
	while(1){
		getline(cin,str);
		if(str.size()){
			int tmp = 0;
			for(auto i = str.cbegin(); i != str.cend();++i){
				if(*i <= '9' && *i >= '0' || *i == ' '){
				}
				else {
					tmp = 1;
				}
			}
			if(!tmp){
				break;
			}
		}
		cout << "输入了非法字符,请重新输入:";
	}
	vector<int> vec;
	const char* s = str.c_str();
	string s1;
	for(auto i = str.cbegin();i != str.cend();++i){
		if(*i != ' '){
			s1 += *i;
			if(i == --str.cend()){
				vec.push_back(atoi(s1.c_str()));
			}
		}else{
			if(!s1.empty()){
				vec.push_back(atoi(s1.c_str()));
			}
			s1 = "";
		}
	}
	int num = 0;
	int sum = 0;
	//输出相邻整数的和
	cout << "---------------------\n";
	for(auto i = vec.cbegin();i != vec.cend();++i){
		sum += *i;
		++num;
		if(num == 2 || i == --vec.cend()){
			cout << sum << endl;
			num = 0;
			sum = 0;
		}
	}
	//输出第1个和最后第1个和
	//输出第2个和最后第2个和
	//...
	cout << "---------------------\n";
	for(auto tb = vec.cbegin(),te = --vec.cend();tb <= te;++tb,--te){
		if(tb == te){
			cout << *tb << endl;
		}else{
			cout << *tb + *te <<endl;
		}
	}
	return 0;
}
