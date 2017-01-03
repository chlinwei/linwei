/*
   闰年练习
   */
#include <stdio.h>
int main() {
	int year = 0;
	printf("请输入一个年份：");
	scanf("%d", &year);
	if ((!(year % 4) && year % 100) || (!(year % 400))) {
	    printf("是闰年\n");
	}
	else {
	    printf("不是闰年\n");
	}
	return 0;
}




