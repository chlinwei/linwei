#include <iostream>
using namespace std;

int main(void)
{
	int* p1 = new int;
	cout << *p1 << endl;//0
	*p1 = 100;
	cout << *p1 << endl;//100
	delete p1;
	p1 = NULL;

	p1 = new int(200);
	cout << *p1 << endl;//200
	(*p1)++;
	cout << *p1 << endl;//201
	delete p1;
	p1 = NULL;

	int* pa = new int[10];
	/*C++2011支持new数组初始化
	int* pa = new int[10]{
				1,2,3,4,5,6,7,8};*/
	for(int i = 0;i < 10;i++){
		pa[i] = i+1;
		cout << pa[i] << ' ';
	}
	cout << endl;
	delete[] pa;
	pa = NULL;
	return 0;
}




