/*
   顺序物理结构演示
   */
#include <stdio.h>
void insert(int *p_num, int size, int num, int post) {
	int pos = 0;
	for (pos = size - 1;pos >= 0;pos--) {
		if (*(p_num + pos) == post) {
			*(p_num + pos + 1) = *(p_num + pos);
			*(p_num + pos) = num;
			break;
		}
		else {
			*(p_num + pos + 1) = *(p_num + pos);
		}
	}
}
void remove_num(int *p_num, int size, int num) {
	int num1 = 0, flag = 0;
	for (num1 = 0;num1 <= size - 1;num1++) {
		if (*(p_num + num1) == num) {
			flag = 1;
		}
		else if (flag) {
			*(p_num + num1 - 1) = *(p_num + num1);
		}
	}
	*(p_num + size - 1) = 0;
}
int main() {
	int arr[10] = {45, 21, 17, 9, 31, 57, 35}, num = 0;
	remove_num(arr, 7, 21);
	for (num = 0;num <= 5;num++) {
        printf("%d ", arr[num]);
	}
	printf("\n");
	insert(arr, 6, 14, 9);
	for (num = 0;num <= 6;num++) {
		printf("%d ", arr[num]);
	}
	printf("\n");
	return 0;
}







