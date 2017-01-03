#include <iostream>
using namespace std;

class A{
public:
   A(void){
   		cout << "A::A()" << endl;
   }	
   ~A(void){
   		cout << "A::~A()" << endl;
   }
};
class B{
public:
	B(void){
		cout << "B::B()" << endl;
	}
	~B(void){
		cout << "B::~B()" << endl;
	}
	A m_a;
};
int main(void)
{
	B b;
	return 0;
}





