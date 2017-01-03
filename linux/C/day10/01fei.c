/*
   生命周期作业
   */
#include <stdio.h>
int fei(int arr[], int size, int num) {
	if (num <= 1) {
		return 1;
	}
	if (!arr[num - 2]) {
		arr[num - 2] = fei(arr, size, num - 2);
	}
	if (!arr[num - 1]) {
		arr[num - 1] = fei(arr, size, num - 1);
	}
	return arr[num - 2] + arr[num - 1];
}
int main() {
	int arr[50] = {0};
	int num = 0;
	printf("请输入一个编号：");
	scanf("%d", &num);
	printf("计算结果是%d\n", fei(arr, 50, num));
	return 0;
}




