/*
   函数练习
   */
#include <stdio.h>
int rabbit(void) {
	int heads = 0, legs = 0, num = 0;
	printf("请输入头的个数和脚的个数：");
	scanf("%d%d", &heads, &legs);
    for (num = 0;num <= heads;num++) {
		if (4 * num + 2 * (heads - num) == legs) {
			return num;
		}
	}
}
int main() {
    int num = rabbit();
	printf("兔子一共有%d只\n", num);
	return 0;
}



