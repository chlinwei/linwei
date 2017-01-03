#include <iostream>
using namespace std;

class Integer{
public:
	Integer(int i = 0):m_i(i){}
	void print(void){
		cout << m_i << endl;
	}
	const Integer operator-(void)const{
		return Integer(-m_i);
	}
	//自定义~乘方的效果
	friend const Integer operator~(
		const Integer& i){
		return Integer(i.m_i*i.m_i);
	}
private:
	int m_i;
};
int main(void)
{
	Integer i(100);
	Integer j = -i;//i.operator-();
	j.print();
	j = ~i;
	j.print();//10000;
	return 0;
}








