/*
   变量演示
   */
#include <stdio.h>
int num;   //全局变量
void func(void) {
	printf("num是%d\n", num);
}
int main() {
	int num = 20;
	printf("num是%d\n", num);
	num = 10;
	func();
	return 0;
}
