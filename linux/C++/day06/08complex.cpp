#include <iostream>
using namespace std;

class Complex{
	public:
		Complex(int r=0,int i=0):m_r(r),m_i(i){}
		void print(void){
			cout << m_r << '+' << m_i << 'i' << 
				endl;
		}
		void print(void)const{//常成员函数与上面的函数构成重载
			//常对象只能调用常函数
			cout << m_r << '+' << m_i << 'i' << 
				endl;
		}

		/*第一个const：修饰返回值，返回常量
		 *第二个const：常引用，支持常量型的右操作数
		 *第三个const：常函数，支持常量型左操作数*/
		const Complex operator+
			(const Complex& c)const{
				return Complex(m_r+c.m_r,m_i+c.m_i);
			}
	private:
		int m_r;
		int m_i;
		friend const Complex operator-(
				const Complex& l,const Complex& r);
};
const Complex operator-(const Complex& l,
		const Complex& r){
	return Complex(l.m_r-r.m_r,l.m_i-r.m_i);
}
int main(void)
{
	const Complex c1(1,2);
	const Complex c2(3,4);
	const Complex c3 = c1 + c2;//c1.operator+(c2);
	c3.print();
	Complex c4 = c1 + c2 + c3;
	c4.print();
	c4 = c3 - c1;//::operator+(c3,c1);
	c4.print();
	return 0;
}









