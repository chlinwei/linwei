/*
   const关键字演示
   */
#include <stdio.h>
void print(const int *p_num, int size) {
	int num = 0;
	for (num = 0;num <= size - 1;num++) {
		printf("%d ", *(p_num + num));
	}
}
int main() {
	int arr[] = {1, 2, 3, 4, 5};
	print(arr, 5);
	printf("\n");
	return 0;
}



