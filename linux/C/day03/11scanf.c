/*
   scanf标准函数练习
   */
#include <stdio.h>
int main() {
	float radius = 0.0f, pi = 3.14f;
	printf("请输入半径：");
	scanf("%g", &radius);
	printf("周长是%g\n", 2 * pi * radius);
	return 0;
}




