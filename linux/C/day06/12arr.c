/*
   数组演示
   */
#include <stdio.h>
int main() {
	int arr[] = {0, 1, 2, 3, 4};   //数组声明语句
	//arr[2] = 10;
	int num = 0;
	/*for (num = 0;num <= 4;num++) {
		arr[num] = num;
	}*/
	for (num = 4;num >= 0;num--) {
		printf("%d ", arr[num]);
	}
	printf("\n");
	return 0;
}



