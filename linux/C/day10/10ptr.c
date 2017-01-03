/*
   const关键字演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	const int *p_num = &num;
	int * const p_num1 = &num;
	//*p_num = 10;   错误
	num = 10;
	printf("请输入一个数字：");
	scanf("%d", p_num);
	printf("*p_num是%d\n", *p_num);
	*p_num1 = 10;
	//p_num1 = NULL;   错误
	return 0;
}



