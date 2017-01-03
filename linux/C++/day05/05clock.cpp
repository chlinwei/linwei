#include <iostream>
#include<unistd.h>//sleep()
#include <cstdio>

using namespace std;
class Clock{
public:
	Clock(bool timer = false)
		:m_hour(0),m_min(0),m_sec(0){
		if(timer){
			time_t t = time(NULL);
			tm* local = localtime(&t);
			m_hour = local->tm_hour;
			m_min = local->tm_min;
			m_sec = local->tm_sec;
		}
	}
	void run(void){
		for(;;){
			//显示时间
			show();
			//计时
			tick();
		}
	}
private:
	void show(void){
		printf("\r%02d:%02d:%02d",m_hour,//%02d 两位不足用0补齐
				m_min,m_sec);
		fflush(stdout);
	}
	void tick(void){
		sleep(1);
		if(++m_sec == 60){
			m_sec = 0;
			if(++m_min == 60){
				m_min = 0;
				if(++m_hour == 24)
					m_hour = 0;
			}
		}
	}
	int m_hour;
	int m_sec;
	int m_min;
};
int main(void)
{
	//Clock clock(true);//时钟
	Clock clock;//计时器
	clock.run();
	return 0;
}




