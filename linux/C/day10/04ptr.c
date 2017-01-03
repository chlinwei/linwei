/*
   指针，数组演示
   */
#include <stdio.h>
int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int *p_num = arr;
	int num = 0;
	for (num = 0;num <= 4;num++) {
		//printf("%d ", arr[num]);
		printf("%d ", p_num[num]);
	}
	printf("\n");
	printf("p_num是%p,p_num + 3是%p, p_num - 3是%p\n", p_num, p_num + 3, p_num - 3);
	printf("&arr[3] - arr是%d\n", &arr[3] - arr);
	return 0;
}





