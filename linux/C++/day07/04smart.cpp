#include <iostream>
using namespace std;
#include <cstdio>
#include <memory>//封转了智能指针
class A{
public:
	A(const string& str):m_str(str){
		cout << "A::A()" << endl;
	}
	~A(void){
		cout << "A::~A()" << endl;
	}
	string m_str;
};
class PA{
public:
	PA(A* pa):m_pa(pa){}
	~PA(void){
		if(m_pa){
			delete m_pa;
			m_pa = NULL;
		}
	}
	A& operator*(void)const{
		return *m_pa;
	}
	A* operator->(void)const{
		return m_pa;
	}
private:
	A* m_pa;
};
int main(void)
{
	//A a;
	//A* p = new A;
#if 0
	PA pa(new A("hello world"));
	cout << (*pa).m_str << endl;
	cout << pa->m_str << endl;
#else
	auto_ptr<A> pa(new A("hello world!"));
	cout << (*pa).m_str << endl;
	cout << pa->m_str << endl;
#endif
	FILE* fp=fopen("non.txt","r");
	if(fp == NULL){
		return -1;
	}
	//delete p;
	return 0;
}






