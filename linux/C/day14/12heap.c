/*
   动态分配内存练习
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *create(int num) {
	int num1 = 0;
	int *p_num = (int *)malloc(num * sizeof(int));
	if (p_num) {
		for (num1 = 0;num1 <= num - 1;num1++) {
			*(p_num + num1) = rand() % 36 + 1;
		}
	}
	return p_num;
}
int main() {
	int num = 0, num1 = 0, *p_num = NULL;
    srand(time(0));
	printf("请输入数字个数：");
	scanf("%d", &num);
	p_num = create(num);
	if (p_num) {
		for (num1 = 0;num1 <= num - 1;num1++) {
			printf("%d ", *(p_num + num1));
		}
		printf("\n");
		free(p_num);
		p_num = NULL;
	}
	return 0;
}




