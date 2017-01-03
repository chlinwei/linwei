#include <iostream>
using namespace std;

class A{
public:
	A(int i= 0){
		cout << "A::A(int)" << endl;
	}
};
class B{
public:
	B(void){
		cout << "B::B(void)" << endl;
	}
private:
	A m_a;
};
int main(void)
{
	B b;
	return 0;
}
