#include <iostream>
using namespace std;

class Counter{
public:
	Counter(int data = 0):m_data(data){}
	Counter& add(void){
		++m_data;
		return *this;//返回自引用
	}
	void destroy(void){
		delete this;//自销毁
	}
	int m_data;
};
int main(void)
{
	Counter cn;
	cout << cn.add().add().add().m_data <<endl;
	cout << cn.m_data << endl;//3

	Counter* pcn = new Counter;
	//delete pcn;
	pcn->destroy();
	return 0;
}






