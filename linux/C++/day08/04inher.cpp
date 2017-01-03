#include <iostream>
using namespace std;

class Bass{
public:
	Bass(void):m_i(0){
		cout << "Bass::Bass()" << endl;
	}
	Bass(int i):m_i(i){
		cout << "Bass::Bass(int)" << endl;
	}
	~Bass(void){
		cout << "Base::~Bass()" << endl;
	}
	int m_i;
};
class Member{
public:
	Member(void):m_i(0){
		cout << "Member::Member()" << endl;
	}
	Member(int i):m_i(i){
		cout << "Member::Member(int)" << endl;
	}
	~Member(void){
		cout << "Member::~Member()" << endl;
	}
	int m_i;
};
class Derived:public Bass{
public:
	Derived(void){
		cout << "Derived::Derived()" << endl;
	}
	Derived(int i,int j):Bass(i),m_member(j){
		cout << "Derived::Derived(int)"<< endl;
	}
	~Derived(void){
		cout << "Derived::~Derived()" << endl;
	}
	Member m_member;
};
int main(void)
{
	Derived d;//首先构造Derived的成员,因为成员是继承Base来的
	//所以顺序是Base的构造,再次是Member的构造,最后是Derived的构造 
	//析构的顺序和构造的顺序是反的
	cout << d.m_i << endl;//0
	//Derived d2(100);//这里,Derived的类里没有匹配的类,所以报错,
	//如果将Derived(int i,int j):Base(i),m_member(j){}改为
	//Derived(int i,int j=0)...就对了 

	//cout << d2.m_i << endl;
	//Derived d3(100,200);
	//cout << d3.m_i << d3.m_member.m_i << endl;
	Derived* p = new Derived;
	Bass* pb = p;//指向子类对象的基类指针
	//delete pb;//内存泄露,pb指向的是Derived类型的存储区,
	//delete时,pb会把Derived里的东西释放掉,所以出现内存泄露
	delete p;

	//Bass* pb2 = new Derived;
	//delete pb2;//内存泄露
	return 0;
}











