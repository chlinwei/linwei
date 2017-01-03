#include <iostream>
using namespace std;

int main(void)
{
	enum Color{
		RED,
		GREEN,
		BLUE = 100,
		YELLOW//101
	};
	Color c;
	//c = 100;//error
	c = BLUE;//ok
	cout << c << endl;
	return 0;
}



