#include <iostream>
using namespace std;

int foo(int a){
	cout << "foo(int)" << endl;
}
void foo(int a,int b){
	cout << "foo(int,int)" << endl;
}
/*重载与参数名没有关系
void foo(int b,int a){
	cout << "foo(int,int)" << endl;
}*/
double foo(void){
	cout << "foo(void)" << endl;
}
void foo(int a,float b){
	cout << "foo(int,float)" << endl;
}
void foo(float b,int a){
	cout << "foo(float,int)" << endl;
}
int main(void)
{
	foo(100);
	foo(100,200);
	foo();
	foo(100,1.234f);
	foo(1.234f,100);
	return 0;
}


