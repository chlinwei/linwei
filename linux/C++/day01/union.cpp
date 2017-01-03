#include <iostream>
using namespace std;
#include <cstdio>

int main(void)
{
	union {//匿名联合
		unsigned char uc[4];
		unsigned int un;
	};
	un = 0x12345678;
	for(int i=0;i<4;i++){
		printf("0x%x ",uc[i]);
	}
	cout << endl;
	return 0;
}

