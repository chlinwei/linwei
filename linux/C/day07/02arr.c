/*
   数组练习
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int arr[7] = {0}, num = 0, tmp = 0, cnt = 0;
	srand(time(0));
	/*for (num = 0;num <= 6;num++) {
		arr[num] = rand() % 36 + 1;
	}*/
	do {
		tmp = rand() % 36 + 1;
		for (num = 0;num <= cnt - 1;num++) {
			if (tmp == arr[num]) {
				break;
			}
		}
		if (num == cnt) {
			arr[cnt] = tmp;
			cnt++;
		}
	} while (cnt < 7);
	for (num = 0;num <= 6;num++) {
		printf("%d ", arr[num]);
	}
	printf("\n");
	return 0;
}




