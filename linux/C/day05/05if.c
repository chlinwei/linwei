/*
   if分支演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	printf("请输入一个数字：");
	scanf("%d", &num);
	if (num < 0) {
	    printf("负数\n");
	}
	else if (num & 1) {
	    printf("奇数\n");
	}
	else {
	    printf("偶数\n");
	}
	return 0;
}





