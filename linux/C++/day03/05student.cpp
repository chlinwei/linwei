#include <iostream>
using namespace std;

/*struct*/
class Student{
public:
	//行为
	void eat(const string& food){
		cout << "我吃" << food << endl;
	}
	void sleep(int time){
		cout << "我睡了" << time << 
			"小时" << endl;
	}
	void learn(const string& course){
		cout << "我学" << course << endl;
	}
	void who(void){
		cout << "我叫" << m_name << ",今年"
			<< m_age << "岁，学号" 
			<< m_no << endl;
	}
	/*私有的成员不能在类的外部访问，但可
	  以提供公有接口函数，间接访问这些私有
	  成员,同时实现对非法数据的限定，控制
	  合理性*/
	void setName(const string& name){
		if(name == "二")
			cout << "你才" << name << endl;
		else
			m_name = name;
	}
	void setAge(int age){
		if(age < 0 )
			cout << "无效年龄" << endl;
		else
			m_age = age;
	}
	void setNo(int no){
		if(no < 1000)
			cout << "无效的学号" << endl;
		else
			m_no = no;
	}
private:
	//属性
	string m_name;
	int m_age;
	int m_no;
};
int main(void)
{
	//创建对象，对象的实例化
	Student s;/*
	s.m_name = "张飞";
	s.m_age = 27;
	s.m_no = 10011;
	s.m_name = "二";*/
	s.setName("二");
	s.setAge(-20);
	s.setNo(0);

	s.setName("唐僧");
	s.setAge(29);
	s.setNo(10086);

	s.who();
	s.eat("牛肉");
	s.sleep(12);
	s.learn("C++");
	return 0;
}




