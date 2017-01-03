/*
   变长数组练习
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int max = 0, num = 0;
	srand(time(0));
	printf("请输入数字个数：");
	scanf("%d", &max);
	int arr[max];
	for (num = 0;num <= max - 1;num++) {
		arr[num] = rand() % 36 + 1;
	}
	for (num = 0;num <= max - 1;num++) {
		printf("%d ", arr[num]);
	}
	printf("\n");
	return 0;
}



