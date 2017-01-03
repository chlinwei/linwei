#include <iostream>
using namespace std;

class Teacher{
public:
	/*Teacher(void){
		cout << "缺省构造函数" << endl;
	}*/
	void who(void){
		cout << m_name << "," << m_age << endl;
	}
private:
	/*会自动调用string的无参构造*/
	string m_name;//类类型
	int m_age;//基本类型
};

int main(void)
{
	Teacher t;
	t.who();
	return 0;
}


