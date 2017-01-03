#include <iostream>
#include <fstream>
using namespace std;

int main(void){
	fstream fs("seek.txt");
	fs << "0123456789";
	fs.seekp(-3,ios::cur);
	fs << "XYZ";

	fs.seekg(3,ios::beg);
	string str;
	fs >> str;
	cout << str << endl;
}
