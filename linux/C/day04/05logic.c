/*
   逻辑操作符演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	printf("!8是%d\n", !8);
	printf("3 < 7 < 5是%d\n", 3 < 7 < 5);
	1 || ++num;
	printf("num是%d\n", num);
	0 && ++num;
	printf("num是%d\n", num);
	return 0;
}




