/*
   for循环练习
   */
#include <stdio.h>
int main() {
	int num = 0;
	for (num = 0;num <= 40;num++) {
		if (4 * num + 2 * (40 - num) == 100) {
			printf("兔子一共有%d只，鸡一共有%d只\n", num, 40 - num);
			break;
		}
	}
	printf("num是%d\n", num);
	return 0;
}
