#include <iostream>
using namespace std;

int main(void)
{
	int a = 123;
	int& b = a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	b++;
	cout << "a=" << a << endl;//124
	cout << "b=" << b << endl;//124
	
	int c = 321;
	b = c;//将c赋值给a
	cout << "a=" << a << endl;//321
	return 0;
}


