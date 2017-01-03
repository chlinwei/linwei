#include <iostream>
using namespace std;

class A{};
class B:public A{};
void func(void){
	throw B();
	//throw A();
}
int main(void)
{
	try{
		func();
	}
	catch(A& ex){
		cout << "catch:A" << endl;
		return -1;
	}
	catch(B& ex){
		cout << "catch:B" << endl;
		return -1;
	}
	return 0;
}
