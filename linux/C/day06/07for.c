/*
   多重循环练习
   */
#include <stdio.h>
int main() {
	int num = 0, num1 = 0;
	for (num = 0;num <= 2;num++) {
		for (num1 = 0;num1 <= 5;num1++) {
			if (5 * num + 2 * num1 <= 10) {
				printf("5元钱有%d张，2元钱有%d张，1元钱有%d张\n", num, num1, 10 - 5 * num - 2 * num1);
			}
		}
	}
	return 0;
}
