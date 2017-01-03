/*
   字符串练习
   */
#include <stdio.h>
#include <string.h>
int main() {
	int rank = 0;
	char ranks[50] = {0};
	char tmp[10] = {0};
	do {
		printf("请输入一个考试成绩：");
		scanf("%d", &rank);
		if (rank < 0) {
			break;
		}
        sprintf(tmp, "%d,", rank);
		strcat(ranks, tmp);
	} while (1);
	ranks[strlen(ranks) - 1] = 0;
	printf("%s\n", ranks);
	return 0;
}




