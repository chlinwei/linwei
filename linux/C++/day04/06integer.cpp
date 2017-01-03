#include <iostream>
using namespace std;

class Integer{
public:
	Integer(void){
		cout << "Integer::Integer()" << endl;
		m_data = 0;
	}
	/*类型转换构造函数*/
	/*explicit要求编译器必须显示进行转换*/
	explicit Integer(int i){
		cout << "Integer::Integer(int)"<< endl;
		m_data = i;
	}
	void print(void){
		cout << m_data << endl;
	}
private:
	int m_data;
};
int main(void)
{
	Integer i;//无参构造
	i.print();
	/*编译器会试图从Integer类中找相应的构造函
	  数，实现把100转换成Integer对象*/
	//i = 100;//单参构造
	//i.print();
	//显示转换
	i = static_cast<Integer>(200);
	//i = (Integer)200;
	//i = Integer(200);
	i.print();
}





