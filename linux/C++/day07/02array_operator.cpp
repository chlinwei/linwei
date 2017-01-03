#include <iostream>
using namespace std;
class Array{
public:
	Array(int size)
		:m_data(new int[size]),m_size(size){}
	~Array(void){
		delete[] m_data;
		m_data = NULL;
	}
	int& operator[](int i){
		return m_data[i];
	}
	/*const int& operator[](int i)const{
		return m_data[i];
	}*/
	int operator[](int i)const{
		//return m_data[i];
		//复用上面的非常版本
		return const_cast<Array&>(*this)[i];
	}
private:
	int* m_data;
	int m_size;
};
int main(void)
{
	Array a(10);
	a[0] = 10;
	a[2] = 12;
	a[5] = 15;
	cout << a[0] << ',' << a[2] << ',' 
		<< a[5] << endl;
	const Array& r = a;
	cout << r[0] << ',' << r[2] << ' ' 
		<< r[5] << endl;
	//r[0] = 11;//error
	return 0;
}









