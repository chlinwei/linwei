#include <iostream>

namespace ns1{
	void func(void){
		std::cout << "ns1::func()" 
							<< std::endl;
	}
}
int main(void)
{
	ns1::func();
	return 0;
}
