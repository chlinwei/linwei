#include <iostream>
using namespace std;

class Student{
public:
	Student(const string& name,int age,
		int no){
		cout << "构造函数" << endl;
		m_name = name;
		m_age = age;
		m_no = no;
	}
	void who(void){
		cout << m_name << ',' << m_age
			<< ',' << m_no << endl; 
	}
private:
	string m_name;
	int m_age;
	int m_no;
};
int main(void)
{
	/*两种方式等价*/
	Student s("唐僧",25,10011);
	Student s2 = Student("关羽",30,10012);
	s.who();
	s2.who();

	Student sa[2] = {
		Student("悟净",20,10086),
		Student("悟能",22,10087)};
	sa[0].who();
	sa[1].who();

	Student* ps = new Student("赵云",10,123);
	ps->who();
	delete ps;
	ps = NULL;

	ps = new Student[2]{
		Student("刘备",30,10001),
		Student("曹操",35,10002)};
	ps[0].who();
	ps[1].who();
	delete[] ps;
	ps = NULL;

	return 0;
}






