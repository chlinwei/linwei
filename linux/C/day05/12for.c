/*
   for循环演示
   */
#include <stdio.h>
int main() {
	int num = 0, num1 = 0;
	/*for (num = 1;;num++) {
		printf("%d\n", num);
	}*/
	/*for (num = 1, num1 = 9;num <= num1;num++, num1--) {
		printf("%d X %d = %d\n", num, num1, num * num1);
	}*/
	for (int num2 = 1;num2 <= 5;num2++) {
		printf("%d ", num2);
	}
	printf("\n");
	//printf("num2是%d\n", num2);   错误
	return 0;
}





