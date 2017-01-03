#include <iostream>
using namespace std;
class Human{
public:
	Human(const string& name,int age):
		m_name(name),m_age(age){}
	friend ostream& operator<<(ostream& os,
		const Human& h){
		return os << h.m_name << ',' <<h.m_age;
	}
private:
	string m_name;
	int m_age;
};
class Student:public Human{
public:
	Student(const string& name,int age,int no,
		const string& course):Human(name,age),
		m_no(no),m_course(course){}
	friend ostream& operator<<(ostream& os,
		const Student& s){
		//这里强制类型转换,
		//复用Human中的
		return os << (Human&)s << ',' << s.m_no
			<< ',' << s.m_course;
	}
private:
	int m_no;
	string m_course;
};
int main(void){
	Student s("张飞",25,100011,"C++");
	cout << s << endl;
	return 0;
}





