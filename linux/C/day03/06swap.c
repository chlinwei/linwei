/*
   交换变量内容演示
   */
#include <stdio.h>
int main() {
	int num = 3, num1 = 7, tmp = 0;
    tmp = num;
	num = num1;
	num1 = tmp;
	printf("num是%d,num1是%d\n", num, num1);
	return 0;
}




