#ifndef __STU_H
#define __STU_H
#include <iostream>
using namespace std;

class Student{
public:
	Student(const string& name);
	void who(void);
private:
	string m_name;
};

#endif//__STU_H

