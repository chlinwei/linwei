#include "stu.h"

//使用作用域限定符，说明属于哪个类
Student::Student(const string& name){
	m_name = name;
}
void Student::who(void){
	cout << m_name << endl;
}
