#include <iostream>
using namespace std;

class Square{
public:
	double operator()(double x)const{
		return x * x;
	}
	int operator()(int a,int b,int c=9)const{
		return a + b - c;
	}
};
int main(void)
{
	Square sq;
	cout<<sq(13.4)<<endl;//sq.operator()(13.4)
	cout << sq(10,40,20) << endl;//30
	cout << sq(10,40) << endl;//41
	return 0;
}





