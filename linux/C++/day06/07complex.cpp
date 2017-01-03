#include <iostream>
using namespace std;

class Complex{
public:
	Complex(int r=0,int i=0):m_r(r),m_i(i){}
	void print(void){
		cout << m_r << '+' << m_i << 'i' << 
			endl;
	}
	Complex add(Complex c){
		return Complex(m_r+c.m_r,m_i+c.m_i);
	}
private:
	int m_r;
	int m_i;
};
int main(void)
{
	Complex c1(1,2);
	Complex c2(3,4);
	c1.print();
	c2.print();
	Complex c3 = c1.add(c2);
	c3.print();
	//c4=c1+c2+c3
	Complex c4 = c3.add(c1);
	c4 = c4.add(c2);
	c4.print();
	return 0;
}









