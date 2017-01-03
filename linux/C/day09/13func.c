/*
   生命周期演示
   */
#include <stdio.h>
void func(void) {
	static int num = 20;
	printf("num是%d\n", num);
	num = 10;
}
void func1() {
	int num = 10;
	int num1 = 11;
	int num2 = num + num1;
}
int main() {
	func();
	func1();
	func();
	return 0;
}



