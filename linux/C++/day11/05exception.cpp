#include <iostream>
using namespace std;

class FileError{};
class MemoryError{};
void foo(void)throw(MemoryError,FileError);/*{
	//throw -1;
	throw FileError();
}*/
int main(void)
{
	try{
		foo();
	}
	catch(FileError& ex){
		cout << "file error!" << endl;
		return -1;
	}
	catch(MemoryError& ex){
		cout << "memory error!" << endl;
		return -1;
	}
	catch(...){
		cout << "other error!" << endl;
		return -1;
	}
	return 0;
}

void foo(void)throw(FileError,MemoryError){
	//throw -1;
	throw FileError();
}


