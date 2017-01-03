/*
   形式参数演示
   */
#include <stdio.h>
void print(int num) {
	printf("%d\n", num);
}
int main() {
	print(6);
	print(6 + 2);
	return 0;
}
