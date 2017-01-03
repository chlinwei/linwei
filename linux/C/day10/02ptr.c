/*
   指针变量演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	int *p_num = &num, *p_num1 = NULL;   //指针变量声明
	p_num = &num;
	*p_num = 10;
	return 0;
}
