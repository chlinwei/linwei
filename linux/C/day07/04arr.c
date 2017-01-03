/*
   数组练习
   */
#include <stdio.h>
int main() {
	int card[17] = {0}, arr[] = {7, 
		9, 10, 5, 8, 4, 2, 1, 6, 3,
	    7, 9, 10, 5, 8, 4, 2}, 
		arr1[] = {1, 0, -1, 9, 8,
		7, 6, 5, 4, 3, 2};
    int num = 0, sum = 0;
	for (num = 0;num <= 16;num++) {
        printf("请输入一个数字：");
		scanf("%d", &card[num]);
	}
	for (num = 0;num <= 16;num++) {
		sum += card[num] * card[num];
	}
	if (arr1[sum % 11] == -1) {
		printf("最后数位应该是X\n");
	}
	else {
		printf("最后数位应该是%d\n", arr1[sum % 11]);
	}
	return 0;
}



