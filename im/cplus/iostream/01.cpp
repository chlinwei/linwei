#include <fstream>
using namespace std;
int main(void){
	ofstream myfile;
	myfile.open("a.txt",ios::out | ios::trunc);
	if(myfile){
		myfile << "我是临危"
			<< "今年22岁"
			<< "今天是2016,7,17,17:33";
	}
	return 0;
}
