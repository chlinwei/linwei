#include <iostream>
using namespace std;
#include <cstdlib>

class A{
public:
	A(void){
		cout << "A::A()" << endl;
	}
	~A(void){
		cout << "A::~A()" << endl;
	}
	static void* operator new(size_t size){
		cout << "A::new" << endl;
		void* pv = malloc(size);
		return pv;
	}
	static void operator delete(void* pv){
		cout << "A::delete" << endl;
		free(pv);
	}
};
int main(void)
{
	//1)(A*)operator new(sizeof(A))
	//2)pa->A()
	A* pa = new A;
	//1)pa->~A()
	//2)operator delete(pa)
	delete pa;
	return 0;
}










