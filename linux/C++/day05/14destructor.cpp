#include <iostream>
using namespace std;
class A{
public:
	~A(void){
		cout << "A::~A()" << endl;
	}
};

int main(void)
{
	do{
		A a1;
		cout << "test1" << endl;
		A *a2 = new A;
		delete a2;//-->A::~A()
		cout << "test3" << endl;
	}while(0);//-> A::~A()
	cout << "test2" << endl;
	return 0;
}


