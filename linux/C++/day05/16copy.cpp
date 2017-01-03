#include <iostream>
using namespace std;

class Integer{
public:
	Integer(int data = 0)
		:m_data(new int(data)){}
	/*缺省拷贝构造，浅拷贝
	Integer(const Integer& that)
		:m_data(that.m_data){}*/
	/*自定义深拷贝*/
	Integer(const Integer& that)
		:m_data(new int(*that.m_data)){}
	/*缺省拷贝赋值函数*/
	/*Integer& operator=(const Integer& that){
		m_data = that.m_data;
		return *this;
	}*/
	/*深拷贝赋值函数*/
	Integer& operator=(const Integer& that){
		if(&that != this){//防止自赋值
			delete m_data;//释放旧资源
			//分配新资源，拷贝新数据
			m_data = new int(*that.m_data);
		}
		return *this;//返回自引用
	}
	~Integer(void){
		cout << "Integer::~Integer()" << endl;
		delete m_data;
		m_data = NULL;
	}
	int get(void){
		return *m_data;
	}
private:
	int* m_data;
};
//A a2(a1):拷贝构造
//a3=a2:拷贝赋值
//A a3=a1:拷贝构造
//总结:从无到有是拷贝构造,从有调用的是拷贝赋值运算
int main(void)
{
	Integer i(100);
	cout << i.get() << endl;
	Integer i2(i);//拷贝构造
	cout << i2.get() << endl;
	Integer i3;
	i3 = i2;//拷贝赋值，i3.operator=(i2).
	cout << i3.get() << endl;
	return 0;
}


