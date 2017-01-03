/*单例模式：懒汉式*/
#include <iostream>
using namespace std;

class A{
public:
	static A& getInstance(void){
		if(!s_instance)
			s_instance = new A(1234);
		++s_counter;
		return *s_instance;
	}
	void release(void){
		//s_counter >0 && s_counter == 1
		if(s_counter && --s_counter == 0){
			delete this;//自销毁
		}
	}
private:
	A(int data = 0):m_data(data){}
	~A(void){
		s_instance = NULL;
	}
	A(A const& that);
	int m_data;
	static A* s_instance;
	static int s_counter;//记录对象别名个数
};
A* A::s_instance = NULL;
int A::s_counter = 0;

int main(void)
{
	A& a1 = A::getInstance();
	A& a2 = A::getInstance();
	cout << &a1 << ',' << &a2 << endl;
	a1.release();
	a2.release();
	return 0;
}




