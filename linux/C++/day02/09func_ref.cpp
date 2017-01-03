#include <iostream>
using namespace std;

struct Student{
	char name[128];
	int age;
};
void print(const Student& s){
	cout << s.name << ','<<
				s.age/*++*/ << endl;
}
int main(void)
{
	const Student s = {"张飞",28};
	print(s);
}



