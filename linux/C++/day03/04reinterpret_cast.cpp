#include <iostream>
using namespace std;

int main(void)
{
	int addr = 0x12345678;
	void* ps = 
		reinterpret_cast<void*>(addr);
	cout << ps << endl;
	char Text[]=
		"0001\00012345678\000000000";
	struct T{
		char type[5];
		char acc[9];
		char passwd[7];
	};
	T* pt = reinterpret_cast<T*>(Text);
	cout << pt->type << endl;
	cout << pt->acc << endl;
	cout << pt->passwd << endl;
	return 0;
}



