#include <iostream>
using namespace std;

class Student{
public:
	Student(const string& name,int age)
		:m_name(name),m_age(age){
		/*m_name = name;
		m_age = age;*/
	}
	void who(void){
		cout << m_name << ',' << 
			m_age << endl;
	}
private:
	string m_name;
	int m_age;
};
int main(void){
	Student s("张飞",25);
	s.who();
	return 0;
}


