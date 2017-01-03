#include <iostream>
using namespace std;
#include <cstdio>
class Student{
public:
	Student(const string& name):m_name(name){}
	double m_d;
	string m_name;
};
int main(void)
{
	string Student::*pname = &Student::m_name;
	Student s1("张飞");
	Student s2("赵云");
	//.* 成员指针解引用运算符
	cout << s1.*pname << endl;
	cout << s2.*pname << endl;
	Student* ps = &s2;
	//->* 间接成员指针解引用运算符
	cout << ps->*pname << endl;

	//对象地址+成员变量指针的相对地址
	printf("pname=%p\n",pname);
	printf("s1=%p\n",&s1);
	printf("&s1.m_name=%p\n",&s1.m_name);
	return 0;
}




