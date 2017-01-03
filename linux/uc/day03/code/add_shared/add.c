#include "add.h"
//#include "../add.h"
//#include <add.h>

//定义计算两个参数和的函数
int add_int(int ia,int ib)
{
	printf("我是共享库文件\n");
	return ia + ib;
}

