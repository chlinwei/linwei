#include <iostream>
using namespace std;

int main(void)
{
	//int& r = 100;//error
	const int& rc = 100;//ok
	cout << rc << endl;
	return 0;
}
