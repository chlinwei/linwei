#include <iostream>
using namespace std;

class Integer{
public:
	Integer(int i = 0):m_i(i){}
	void print(void){
		cout << m_i << endl;
	}
	//前加加
	Integer& operator++(void){
		++m_i;
		return *this;
	}
	//前减减
	friend Integer& operator--(Integer& i){
		--i.m_i;
		return i;
	}
	//后加加,多一个哑元参数，区分前++
	const Integer operator++(int){
		Integer old = *this;
		++*this;//复用前++
		return old;
	}
	//后减减
	friend const Integer operator--(
			Integer& i,int){
		Integer old = i;
		--i;
		return old;
	}
private:
	int m_i;
};
int main(void)
{
	Integer i(123);
	Integer j = ++i;
	i.print();//124
	j.print();//124
	j = ++++++i;
	i.print();//127
	j.print();//127

	j = --i;
	i.print();//126
	j.print();//126

	j = i++;
	i.print();//127
	j.print();//126

	j = i--;
	i.print();//126
	j.print();//127


	return 0;
}











