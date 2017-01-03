#include <iostream>
#include <cstdio>
using namespace std;

class FileError{
public:
	FileError(void){}
	FileError(const string& file,int line):
		m_file(file),m_line(line){
		cout << "出错位置:"  << m_file << ','
			<< m_line << endl;	
	}
private:
	string m_file;
	int m_line;
};
class A{
public:
	A(void){cout << "A::A()" << endl;}
	~A(void){cout << "A::~A()" << endl;}
};
int func3(void){
	A a;
	FILE *fp = fopen("none.txt","r");
	if(!fp){
		throw FileError(__FILE__,__LINE__);
		throw FileError();
		throw -1;//跳转到当前作用域"}"
	}
	//...
	fclose(fp);
	return 0;
}
int func2(void){
	A a;
	func3();
	//...
	return 0;
}
int func1(void){
	A a;
	func2();
	//...
	return 0;
}
int main(void)
{
	try{
		func1();
		//...
	}
	catch(int ex){
		cout << "ex=" << ex << endl;
		cout << "file open error" << endl;
		return -1;
	}
	catch(FileError ex){
		cout << "file open error2" << endl;
		return -1;
	}
	return 0;
}

