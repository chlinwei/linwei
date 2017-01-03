/*
   猜数练习
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int num = 0, guess = 0;
	srand(time(0));
	num = rand() % 100;
	for (;;) {
		printf("请猜一个数字：");
		scanf("%d", &guess);
		if (guess > num) {
			printf("猜大了\n");
		}
		else if (guess < num) {
			printf("猜小了\n");
		}
		else {
			printf("猜对了\n");
			break;
		}
	}
	return 0;
}






