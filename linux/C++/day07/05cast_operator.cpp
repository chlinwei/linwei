#include <iostream>
using namespace std;
class Integer{
public:
	//int -> Integer
	Integer(int data = 0):m_data(data){}
	//Integer -> int
	//类型转换操作符函数
	operator int(void)const{
		cout << "类型转换操作符函数" << endl;
		return m_data;
	}
private:
	int m_data;
};

int main(void)
{
	Integer i1;
	i1 = 100;
	cout << i1 << endl;//Integer->int
	int i2 = i1;//Integer->int
	cout << i2 << endl;
	return 0;
}





