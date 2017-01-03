#include <iostream>
using namespace std;

class Phone{
public:
	Phone(const string& number):
		m_number(number){}
	void call(const string& number){
		cout << m_number << "打给" << number <<
			endl;
	}
private:
	string m_number;
};
class Player{
public:
	Player(const string& media):
		m_media(media){}
	void play(const string& music){
		cout << m_media << "播放器播放" <<
			music << endl;
	}
private:
	string m_media;
};
class Computer{
public:
	Computer(const string& os):m_os(os){}
	void run(const string& app){
		cout << "在" << m_os << "系统上运行"
			<< app << endl;
	}
private:
	string m_os;
};
/*class SmartPhone:public Phone,public Player,*/
	//public Computer{
//public:
	//SmartPhone(const string& number,
		//const string& media,const string& os):
			//Phone(number),Player(media),
			//Computer(os){}	
/*};*/
class SmartPhone:public Phone,public Player,public Computer {
	public:
	SmartPhone(const string& number,const string& media,const string& os):
		Player(media),Computer(os),Phone(number){}
};
int main(void)
{
	SmartPhone sp("010-10086","MP4","Android");
	sp.call("010-62132018");
	sp.play("最炫小苹果");
	sp.run("Angry Bird");

	SmartPhone* p1 = &sp;//向上构造
	Phone* p2 = p1;
	Player* p3 = p1;
	Computer* p4 = p1;
	cout << "p1=" << p1 << endl;
	cout << "p2=" << p2 << endl;
	cout << "p3=" << p3 << endl;
	cout << "p4=" << p4 << endl;

	SmartPhone* p5 = 
		static_cast<SmartPhone*>(p4);
	cout << "p5=" << p5 << endl;

	SmartPhone* p6 = 
		reinterpret_cast<SmartPhone*>(p4);
	cout << "p6=" << p6 << endl;
	return 0;
}






