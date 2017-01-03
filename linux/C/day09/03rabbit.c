/*
   形式参数练习
   */
#include <stdio.h>
int rabbit(int heads, int legs) {
	int num = 0;
	for (num = 0;num <= heads;num++) {
		if (4 * num + 2 * (heads - num) == legs) {
			return num;
		}
	}
}
int main() {
	int heads = 0, legs = 0, num = 0;
	printf("请输入头和脚的个数：");
	scanf("%d%d", &heads, &legs);
	num = rabbit(heads, legs);
	printf("兔子一共有%d只，鸡一共有%d只\n", num, heads - num);
	return 0;
}



