/*
   数组练习
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int arr[13] = {0}, max = 0, num = 0, num1 = 0, max_num = 12, cnt = 0;
	srand(time(0));
    printf("请输入数字：");
	scanf("%d", &max);
	for (num = 0;num <= max - 1;num++) {
		int tmp = rand() % (max_num + 1);
		cnt = 0;
		for (num1 = 0;num1 <= 12;num1++) {
            if (!arr[num1]) {
				if (tmp == cnt) {
					printf("%d ", num1);
					arr[num1] = 1;
					max_num--;
					break;
				}
				else {
					cnt++;
				}
			}
		}
	}
	printf("\n");
	return 0;
}
