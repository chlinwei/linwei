/*
   函数指针演示
   */
#include <stdio.h>
int add(int num, int num1) {
	return num + num1;
}
int main() {
	int (*p_add)(int, int) = NULL;
	printf("add是%p\n", add);
	p_add = add;
	printf("结果是%d\n", p_add(3, 7));
	return 0;
}




