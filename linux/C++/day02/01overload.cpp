#include <iostream>
using namespace std;
/*char->int,升级转换*/
void bar(int i){
	cout << "bar(1)" << endl;
}
/*char->const char,常量转换*/
void bar(const char c){
	cout << "bar(2)" << endl;
}
/*short->char 降级转换*/
void func(char c){
	cout << "func(1)" << endl;
}
/*short->int 升级转换*/
void func(int n){
	cout << "func(2)" << endl;
}
/*short->long long 过分的升级转换*/
void func(long long ll){
	cout << "func(3)" << endl;
}
/*省略号匹配，优先级最低*/
void hum(int i,...){
	cout << "hum(1)" << endl;
}
/*double -> int ,降级转换*/
void hum(int i,int j){
	cout << "hum(2)" << endl;
}
int main(void)
{
	char c = 'A';
	bar(c);
	short s = 100;
	func(s);
	hum(200,1.234);
	return 0;
}




