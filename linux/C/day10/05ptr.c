/*
   指针演示
   */
#include <stdio.h>
int main() {
	int arr[] = {1, 2, 3, 4, 5}, num = 0;
	int *p_num = arr;
	for (num = 0;num <= 4;num++) {
		//printf("%d ", arr[num]);
		//printf("%d ", *(arr + num));
		printf("%d ", *(p_num + num));
	}
	printf("\n");
	return 0;
}




