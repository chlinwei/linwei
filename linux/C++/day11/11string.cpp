#include <iostream>
#include <sstream>
using namespace std;

int main(void)
{
	istringstream istring;
	string ss("ss 909090090");
	istring.str(ss);
	int i = 0;
	string s;
	istring >> s >> i ;
	cout << s << ',' << i;

	return 0;
}
