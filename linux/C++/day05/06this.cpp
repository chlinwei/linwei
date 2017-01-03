#include <iostream>
using namespace std;

class User{
public:
	User(const string& name = "",int age = 0)
		:m_name(name),m_age(age){
		cout << "构造函数:" << this << endl;
	}
	void print(void){
		cout << m_name << ',' << m_age << endl;
		cout << this->m_name << ','
			<< this->m_age << endl;
	}
	/*
	void print(User* this){
		cout << this->m_name << ....
	}*/
private:
	string m_name;
	int m_age;
};
int main(void)
{
	User user1("张飞",25);
	User user2("赵云",24);
	cout << "user1::" << &user1 << endl;
	cout << "user2::" << &user2 << endl;
	user1.print();//print(&user1)
	user2.print();
	return 0;
}










