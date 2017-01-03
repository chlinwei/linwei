/*
   三目操作符演示
   */
#include <stdio.h>
int main() {
	int num = 0;
	printf("请输入数字：");
	scanf("%d", &num);
	num = num >= 0 ? num : 0 - num;
	//num >= 0 ? num = num : num = 0 - num;    错误
	printf("绝对值是%d\n", num);
	return 0;
}




