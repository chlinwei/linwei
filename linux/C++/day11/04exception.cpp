#include <iostream>
using namespace std;
/*继承标准异常类,覆盖what函数,减少catch分支*/
class FileError:public exception{
public:
	const char* what(void)const throw() {
		return "file open error";
	}
};
int main(void)
{
	try{
		throw FileError();
		char* p = new char[0xffffffff];
	}
	catch (exception& ex){
		cout << ex.what() << endl;
		return -1;
	}
	return 0;
}
