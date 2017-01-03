/*
   指针练习
   */
#include <stdio.h>
int *read(void) {
	static int num;
	printf("请输入一个数字：");
	scanf("%d", &num);
	return &num;
}
int main() {
	int *p_num = read();
	printf("数字是%d\n", *p_num);
	return 0;
}





