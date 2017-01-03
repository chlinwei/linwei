/*
   数组作业
   */
#include <stdio.h>
int main() {
	int arr[5] = {0}, num = 0, sum = 0;
	for (num = 0;num <= 4;num++) {
		printf("请输入一个数字：");
		scanf("%d", &arr[num]);
	}
	for (num = 4;num >= 0;num--) {
		printf("%d ", arr[num]);
	}
	printf("\n");
	for (num = 0;num <= 4;num++) {
		sum += arr[num];
	}
	printf("求和结果是%d\n", sum);
	return 0;
}





