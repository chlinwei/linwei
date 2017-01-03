/*
   位操作符演示
   */
#include <stdio.h>
int main() {
	char ch = ~0xcb;
	int num = ch;
	printf("num是0x%x\n", num);
	printf("3 & 5是%d\n", 3 & 5);
	printf("3 | 5是%d\n", 3 | 5);
	printf("3 ^ 5是%d\n", 3 ^ 5);
	printf("3 << 2是%d\n", 3 << 2);
	num = -128;
	printf("num是0x%x\n", num);
	printf("num >> 2是0x%x\n", num >> 2);
	return 0;
}





