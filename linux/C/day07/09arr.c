/*
   二维数组演示
   */
#include <stdio.h>
int main() {
	int arr[][3] = {{0, 1, 2, 7}, {3, 4}};   //二维数组声明
	int row = 0, col = 0, cnt = 0;
	//arr[1][1] = 10;
	/*for (row = 0;row <= 1;row++) {
		for (col = 0;col <= 2;col++) {
			arr[row][col] = cnt;
			cnt++;
		}
	}*/
	for (row = 0;row <= 1;row++) {
		for (col = 0;col <= 2;col++) {
			printf("%d ", arr[row][col]);
		}
		printf("\n");
	}
	printf("sizeof(arr)是%d\n", sizeof(arr));
	printf("arr是%p,&arr[0][0]是%p\n", arr, &arr[0][0]);
	printf("arr[1]是%p\n", arr[1]);
	printf("&arr[1][0]是%p\n", &arr[1][0]);
	printf("sizeof(arr[1])是%d\n", sizeof(arr[1]));
	return 0;
}



