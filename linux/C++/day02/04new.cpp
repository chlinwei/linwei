#include <iostream>
using namespace std;

int main(void)
{
	int* p1 = new int(10);
	delete p1;
	//p1 = NULL;
	//cout << "*p1=" << *p1 << endl;
	
	int* p2 = new int(10);
	*p1 = 20;//使用野指针,意外修改了p2数据
	cout << "p1=" << p1 << endl;
	cout << "p2=" << p2 << endl;
	cout << "*p2=" << *p2 << endl;
	return 0;
}





