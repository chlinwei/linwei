/*
   sizeof关键字演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	printf("sizeof(num)是%d,sizeof(int)是%d\n", sizeof(num),sizeof(int));
	sizeof(num = 10);
	printf("num是%d\n", num);
	return 0;
}





