#include <iostream>
using namespace std;

struct Student{
	//成员变量
	char name[20];
	int age;
	//成员函数
	void who(void){
		cout << "我叫" << name << ",今年"
			<< age << "岁." << endl;
	}
};
int main(void)
{
	/*struct*/ Student s={"张飞",25};
	s.who();
	return 0;
}






