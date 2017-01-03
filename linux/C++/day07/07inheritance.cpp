#include <iostream>
using namespace std;

//人类(基类)
class Human{
public:
	Human(const string& name,int age):
		//name这个地方必须加const 不加报错
		m_name(name),m_age(age),m_id(123){}
	void eat(const string& food){
		cout << "我在吃" << food << endl;
	}
	void sleep(int time){
		cout << "我睡了" << time << "个小时"
			<< endl;
	}
	const int& id(void)const{
		return m_id;
	}
protected://保护成员可以在子类中访问
	string m_name;
	int m_age;
private:
	int m_id;
};
//学生类(人类的子类)
class Student:public Human{
public:
	//通过初始化表说明基类子对象的初始化方式
	//基类子对象:子类对象包含基类的部分
	Student(const string& name,int age,int no)
		:Human(name,age),m_no(no){}
	void who(void)const{
		cout << "我叫" << m_name << "，今年"
			<< m_age << "岁，学号是" << m_no
			<< endl;
		cout << "id=" << id() << endl;
	}
	void learn(const string& course){
		cout << "我在学" << course << endl;
	}
private:
	int m_no;
};
//教师类(人类的子类)
class Teacher:public Human{
public:
	Teacher(const string& name,int age,
		double salary):Human(name,age),
			m_salary(salary){}
	void who(void)const{
		cout << "我叫" << m_name << ",今年" 
			<< m_age << "岁，工资是" <<
			m_salary << endl;
	}
	void teach(const string& course){
		cout << "我在教" << course << endl;
	}
private:
	double m_salary;
};
int main(void)
{
	Student s("悟空",30,10011);
	s.who();
	s.learn("念经");
	s.eat("水果");
	s.sleep(16);
	Teacher t("唐僧",28,28000.01);
	t.who();
	t.teach("C++");
	t.eat("蔬菜");
	t.sleep(6);

	Human* ph = &s;//向上造型，安全，可以隐式,左边是基类,右边是之类
	ph->eat("桃子");
	ph->sleep(10);
	//ph->learn("linux");
	
	//安全向下造型
	Student* ps = static_cast<Student*>(ph);//静态转换,把指针或这引用专程想要的Student*类型
	//向下转换,左边是子类
	ps->learn("linux");
	ps->who();

	//危险向下造型
	Human h("林黛玉",28);
	Teacher* pt = static_cast<Teacher*>(&h);
	pt->who();
	delete pt;

	return 0;
}
