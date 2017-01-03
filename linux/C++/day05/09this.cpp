#include <iostream>
using namespace std;

class Student;//声明学生类
class Teacher{
public:
	void educate(Student* student);
	void reply(const string& answer){
		m_answer = answer;
	}
private:
	string m_answer;
};
class Student{
public:
	void ask(const string& question,
			Teacher* teacher){
		cout << "问题:" << question << endl;
		teacher->reply(
			"this指针就是指向调用对象的地址");
	}
};
void Teacher::educate(Student* student){
	student->ask("什么是this指针",this);
	cout << "学生回答:" << m_answer << endl;
}
int main(void)
{
	Teacher teacher;
	Student student;
	teacher.educate(&student);
	return 0;
}








