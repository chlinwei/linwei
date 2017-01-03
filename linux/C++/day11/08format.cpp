#include <iostream>
using namespace std;
#include <cmath>

int main(void)
{
	cout << sqrt(200) << endl;
	cout.precision(8);
	cout << sqrt(200) << endl;

	cout.setf(ios::scientific);//科学计数法
	cout << sqrt(200) << endl;

	cout << '[';
	cout.width(12);
	cout.fill('-');//空白‘-’填充
	cout.setf(ios::showpos);//显示正号
	cout.setf(ios::internal);//内插对齐
	cout << 123456;
	cout << ']' << endl;
	return 0;
}
