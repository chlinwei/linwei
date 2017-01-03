#include <iostream>
using namespace std;

class Integer{
public:
	Integer(int data = 0)
		:m_data(new int(data)){} // ????
	~Integer(void){
		cout << "Integer::~Integer()" << endl;
		delete m_data;
		m_data = NULL;
	}
	int get(void){
		return *m_data;
	}
private:
	int* m_data;
};
int main(void)
{
	Integer i(100);
	cout << i.get() << endl;
	return 0;
}


