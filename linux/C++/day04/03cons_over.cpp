#include <iostream>
using namespace std;

class Student{
public:
	Student(const string& name = "无名",
		int age = 0,int no = 0){
		m_name = name;
		m_age = age;
		m_no = no;
	}/*
	Student(const string& name){
		m_name = name;
		m_age = 0;
		m_no = 0;
	}
	Student(void){
		m_name = "无名";
		m_age = 0;
		m_no = 0;
	}*/
	void who(void){
		cout << m_name << ',' << m_age << ','
			<< m_no << endl;
	}
private:
	string m_name;
	int m_age;
	int m_no;
};
int main(void)
{
	Student s("张飞", 25 ,10011);
	s.who();
	Student s2("关羽", 28);
	s2.who();

	Student s3;
	//Student s3 = Student();
	s3.who();
	return 0;
}







