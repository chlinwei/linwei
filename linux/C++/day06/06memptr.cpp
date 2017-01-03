#include <iostream>
using namespace std;

class Student{
public:
	Student(const string& name):m_name(name){}
	void who(void){
		cout << m_name << endl;
	}
	string m_name;
	static int s_data;
	static int s_add(int a,int b){
		return a+b;
	}
};
int Student::s_data = 100;
int main(void)
{
	void (Student::*pwho)(void)=&Student::who;//普通成员指针
	Student s1("张飞");
	Student s2("赵云");
	(s1.*pwho)();

	Student* ps = &s2;
	(ps->*pwho)();

	int *pdata = &Student::s_data;
	cout << *pdata << endl;
	int (*padd)(int,int)=Student::s_add;//静态成员指针
	//普通成员指针和静态成员指针没有什么区别
	cout << padd(100,200) << endl;

	return 0;
}





