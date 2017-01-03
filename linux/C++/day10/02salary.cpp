#include <iostream>
using namespace std;

class Employee{
public:
	Employee(const string& name,int id,
		int grade):m_name(name),m_id(id),
		m_grade(grade){}
	void printInfo(void){//打印员工信息
		printBasic();//公有信息
		printExtra();//特有信息
	}
	void paySalary(void){//计算工资
		cout << "工资:" << 
			calBasic()+calMerit() << endl;
	}
protected:
	double m_attend;//出勤率
private:
	double calBasic(void){
		cout << "出勤天数:" ;
		int attend;
		cin >> attend;
		m_attend = attend/23.0;
		m_basic = s_grade[m_grade-1];
		return m_basic;
	}
	virtual double calMerit(void){
		return m_basic/2;
	}
	void printBasic(void){
		cout << "姓名:" << m_name << endl;
		cout << "工号:" << m_id << endl;
		cout << "职级:" << m_grade << endl;
	}
	virtual void printExtra(void){
		cout << "职位:普通员工" << endl;
	}
	string m_name;
	int m_id;
	int m_grade;
	double m_basic;
	static double s_grade[8];
};
double Employee::s_grade[]={1000,2000,3000,
	4000,5000,6000,7000,8000};
//经理
class Manager:virtual public Employee{
public:
	Manager(const string& name,int id,
		int grade,double bonus):
		Employee(name,id,grade),
		m_bonus(bonus){}
protected:
	void printExtra(void){
		cout << "职位:经理" << endl;
		cout << "绩效奖金:" <<m_bonus << endl;
	}
	double calMerit(void){
		cout << "绩效因数:";
		double factor;
		cin >> factor;
		//绩效奖金*绩效因数*出勤率
		return m_bonus*factor*m_attend;
	}
private:
	double m_bonus;//绩效奖金
};
//技术员
class Technician:virtual public Employee{
public:
	Technician(const string& name,int id,
		int grade,double allow):
		Employee(name,id,grade),
		m_allow(allow){}
protected:
	void printExtra(void){
		cout << "职位:技术员" << endl;
		cout << "研发津贴:"<<m_allow << endl;;
	}
	double calMerit(void){
		cout << "进度因数:";
		double factor;
		cin >> factor;
		//小时数*研发津贴*进度因数*出勤率
		return 8*23*m_allow*factor*m_attend;
	}
private:
	double m_allow;//研发津贴
};
//技术主管
class TechMngr:public Technician,
							public Manager{	
public:	
	TechMngr(const string& name,int id,
		int grade,double allow,double bonus):
		Technician(name,id,grade,allow),
		Manager(name,id,grade,bonus),
		Employee(name,id,grade){}
private:
	void printExtra(void){
		Technician::printExtra();
		Manager::printExtra();
	}
	double calMerit(void){
		return (Technician::calMerit()+
				Manager::calMerit()) / 2;
	}
};
int main(void)
{
	Employee emp("张飞",10010,3);
	emp.printInfo();
	emp.paySalary();
	cout << endl;

	Manager mngr("刘备",10000,6,6000);
	mngr.printInfo();
	mngr.paySalary();
	cout << endl;

	Technician tech("孔明",10086,7,25);
	tech.printInfo();
	tech.paySalary();
	cout << endl;

	TechMngr techmngr("曹操",10088,8,20,8000);
	techmngr.printInfo();
	techmngr.paySalary();
	cout << endl;
	return 0;
}

















