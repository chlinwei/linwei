/*
   数组练习
   */
#include <stdio.h>
int main() {
	int arr[6] = {0}, num = 0, pos = 5;
    printf("请输入一个数字：");
	scanf("%d", &num);
	do {
		arr[pos] = num % 10;
		num /= 10;
		pos--;
	} while (num);
	for (num = pos + 1;num <= 5;num++) {
		printf("%d ", arr[num]);
	}
	printf("\n");
	return 0;
}



