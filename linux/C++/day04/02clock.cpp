#include <iostream>
#include <cstdio>

using namespace std;
class Clock{
public:
	Clock(time_t t){
		tm* local = localtime(&t);
		m_hour = local->tm_hour;
		m_min = local->tm_min;
		m_sec = local->tm_sec;
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
		printf("\r%02d:%02d:%02d",m_hour,
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
	Clock clock(time(NULL));
	clock.run();
	return 0;
}




