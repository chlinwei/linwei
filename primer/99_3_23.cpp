
//创建一个含有10个整数的vector对象,输出结果
//将所有元素值变为原来2倍,输出结果

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int main(void){
    srand((unsigned)time(NULL));//用时间做随机数的种子
    vector<int> vec;
    for(auto i = 0; i < 10;++i){
        vec.push_back(rand() % 101);
    }
    cout << "随机生成10个100以内的整数:";
    for(auto i : vec){
        cout << i << ' ';
    }
    cout <<'\n';
    cout << "将所有元素的值变为原来的2倍:";
    for(auto& i : vec){
        i = 2*i;
    }
    for(auto i : vec){
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
