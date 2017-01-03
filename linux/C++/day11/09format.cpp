#include <iostream>
#include <iomanip>//带参数的流控制符
#include <cmath>
using namespace std;

int main(void)
{
	cout << sqrt(200) << endl;
	cout << setprecision(10) << sqrt(200) 
		<< endl;
	cout << scientific << sqrt(200) << endl;

	cout << '[';
	cout << setw(10) << setfill('$') << showpos
		<< internal << 123456;
	cout << ']' << endl;

	cout << '[';
	cout << setw(16) << hex << left << showbase
		<< 0x123456;
	cout << ']' << endl;
	return 0;
}





