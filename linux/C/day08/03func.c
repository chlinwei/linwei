/*
   多函数程序演示
   */
#include <stdio.h>
void print(void) {
	int num;
	//printf("1\n");
	printf("num是%d\n", num);
	num = 10;
}
void func() {
	int num = 10;
	int num1 = 11;
	int num2 = num + num1;
}
int main() {
	int num = 2;
	print();
	func();
	print();
	//printf("num是%d\n", num);
	return 0;
}
