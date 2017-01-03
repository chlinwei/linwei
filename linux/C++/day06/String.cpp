#include <iostream>
#include <cstring>
using namespace std;

class String{
public:
	//构造函数
	String(const char* str = NULL):
		m_str(strcpy(
			new char[strlen(str?str:"")+1],
			str?str:"")){}
	//析构函数
	~String(void){
		if(m_str){
			delete[] m_str;
			m_str = NULL;
		}		
	}
	//拷贝构造
	String(const String& that):
		m_str(strcpy(
		new char[strlen(that.m_str)+1],
		that.m_str)){}
	//拷贝赋值
	String& operator=(const String& that){
		if(&that != this){
			/*delete[] m_str;
			m_str=new char[
					strlen(that.m_str)+1];
			strcpy(m_str,that.m_str);*/
			char* str = new char[
					strlen(that.m_str)+1];
			delete[] m_str;
			m_str = strcpy(str,that.m_str);
			/*String temp(that);
			swap(m_str,temp.m_str);*/
		}
		return *this;
	}
	//访问接口
	const char* c_str(void)const{
		return m_str;
	}
private:
	char* m_str;
};
int main(void)
{
	String s1("Hello World!");
	cout << s1.c_str() << endl;
	String s2 = s1;//拷贝构造
	cout << s2.c_str() << endl;
	String s3;
	s3 = s2;//拷贝赋值
	cout << s3.c_str() << endl;
	return 0;
}




