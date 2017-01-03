#include <iostream>
using namespace std;
#include <cstring>

class Dummy{
public:
   /* Dummy(const char* psz)*/
		/*:m_len(m_str.length()),m_str(psz){}*/
	Dummy(const char* psz = NULL)
		:m_str(psz ? psz:""),
		m_len(strlen(psz ? psz:"")){}
	size_t m_len;
	string m_str;
};
int main(void)
{
	Dummy d/*("abcdefg")*/;
	cout << d.m_str << ',' << d.m_len << endl;
	return 0;
}
