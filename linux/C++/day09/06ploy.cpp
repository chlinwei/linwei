#include <iostream>
using namespace std;

class Integer{
public:
	Integer(int r):m_r(r){}
	virtual Integer& operator+=
		(const Integer& i){
		m_r += i.m_r;
		return	*this;	
	}
	int m_r;
};
class Complex:public Integer{
public:
	Complex(int r,int i):Integer(r),m_i(i){}
	Complex& operator+=(const Integer& c){
		Integer::operator+=(c); 
		m_i += ((const Complex&)c).m_i;
	}
	int m_i;
};
int main(void)
{
	Complex c1(1,2),c2(3,4);
	c1 += c2;//c1.operator(c2)
	cout << c1.m_r << '+' << c1.m_i << 'i' ;
	cout << endl;
	Integer& i1 = c1;
	Integer& i2 = c2;
	i1 += i2;//i1.operator+=(i2);
	cout << c1.m_r << '+' << c1.m_i << 'i' ;
	cout << endl;
	return 0;
}





