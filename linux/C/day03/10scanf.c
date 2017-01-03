/*
   scanf标准函数演示
   */
#include <stdio.h>
int main() {
	int num = 0, num1 = 0;
	printf("请输入两个数字：");
	scanf("%d%d", &num, &num1);
	printf("num是%d\n", num);
	printf("num1是%d\n", num1);
	return 0;
}



