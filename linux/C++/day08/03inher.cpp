#include <iostream>
using namespace std;

class Bass{};
class Derived:/*private*//*protected*/public  Bass{};
//如果这里为保护继承或者是私有继承,则无法向上构造

int main(void)
{
	Derived d;
	Bass* pb = &d;//向上构造
	cout << pb << ','<< &d << endl;
	//Bass* pb = static_cast<Bass*>(&d);//静态类型转化
	return 0;
}

