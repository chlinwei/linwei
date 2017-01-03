/*
   操作符演示
   */
#include <stdio.h>
int num2;
int main() {
	int num = 0, num1 = 0;
	char chr = 0;
	printf("15 / 6是%d\n", 15 / 6);
	printf("15 %% 6是%d\n", 15 % 6);
	num = chr = 300;
	printf("num是%d\n", num);
	num += 6;
	printf("num是%d\n", num);
	num *= 2 + 3;
	printf("num是%d\n", num);
	num = 10;
	num++;
	printf("num是%d\n", num);
	++num;
	printf("num是%d\n", num);
	num = 10;
	num1 = ++num;
	printf("num是%d,num1是%d\n", num, num1);
	num1 = num++;
	printf("num是%d,num1是%d\n", num, num1);
	num = 10;
	num1 = num++ + ++num;
	printf("num是%d,num1是%d\n", num, num1);
	num2 = 10;
	num1 = num2++ + ++num2;
	printf("num2是%d,num1是%d\n", num2, num1);
	return 0;
}








