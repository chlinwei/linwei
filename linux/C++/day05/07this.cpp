#include <iostream>
using namespace std;

class User{
public:
	/*形参与成员变量名字相同用this指针区分*/
	User(const string& m_name="",int m_age=0)
	{
		this->m_name = m_name;
		this->m_age = m_age;
		cout << "构造函数:" << this << endl;
	}
	void print(void){
		cout << m_name << ',' << m_age << endl;
		cout << this->m_name << ','
			<< this->m_age << endl;
	}
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










