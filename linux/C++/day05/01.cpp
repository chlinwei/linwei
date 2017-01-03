#include <iostream>
using namespace std;
class A{
    public:
        A(void):m_r(4){}
    private:
        const int& m_r;
};
int main(void){
    return 0;
}
