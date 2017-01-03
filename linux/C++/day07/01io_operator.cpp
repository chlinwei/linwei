#include <iostream>
using namespace std;

class Complex{
public:
	Complex(int r=0,int i=0):m_r(r),m_i(i){}
	friend ostream& operator<<(ostream& os,
			const Complex& c){
		return os << c.m_r << '+' << c.m_i
			<< 'i';
	}
	friend istream& operator>>(istream& is,
			Complex& c){
		return is >> c.m_r >> c.m_i;
	}
private:
	int m_r;
	int m_i;
};
int main(void)
{
	Complex c1(12,34),c2(56,78);
	cout << c1 << endl;
	cout << c1 << ',' << c2 << endl;
	cout << "please input:";
	cin >> c1 >> c2;
	cout << c1 << ',' << c2 << endl;
	return 0;
}








