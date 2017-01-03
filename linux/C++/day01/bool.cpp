#include <iostream>
using namespace std;

int main(void)
{
	bool b = false;
	cout << sizeof(b) << endl;
	cout << boolalpha << b << endl;//false
	b = 100;
	cout << b << endl;//true
	b = 3.14;
	cout << b << endl;//true
	b = "helloworld";
	cout << b << endl;//true
	char* p = NULL;
	b = p;
	cout << b << endl;//false

	return 0;
}




