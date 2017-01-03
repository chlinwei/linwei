/*
   递归函数演示
   */
#include <stdio.h>
void print(int num) {
	if (num == 1) {
		printf("1 ");
		return ;
	}
	print(num - 1);
	printf("%d ", num);
}
int main() {
    print(10);
	printf("\n");
	return 0;
}
