/*
   switch...case练习
   */
#include <stdio.h>
int main() {
	int num = 0;
	printf("请输入一个数字：");
	scanf("%d", &num);
	switch (num) {
	case 0:
		printf("假\n");
		break;
	default:
        printf("真\n");
		break;
	}
	return 0;
}




