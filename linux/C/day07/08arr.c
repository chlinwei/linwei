/*
   数组练习
   */
#include <stdio.h>
int main() {
	int max = 0, num = 0, min = 101, max_rank = -1, sum = 0;
	printf("请输入考试成绩的个数：");
	scanf("%d", &max);
	int ranks[max];
	for (num = 0;num <= max - 1;num++) {
		printf("请输入一个考试成绩：");
		scanf("%d", &ranks[num]);
	}
	for (num = 0;num <= max - 1;num++) {
		if (min > ranks[num]) {
			min = ranks[num];
		}
		if (max_rank < ranks[num]) {
			max_rank = ranks[num];
		}
		sum += ranks[num];
	}
	printf("最大成绩是%d,最小成绩是%d,总成绩是%d\n", max_rank, min, sum);
	return 0;
}



