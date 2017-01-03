/*
   扫雷练习
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int arr[10][10] = {0}, row = 0, col = 0, mines = 0, num = 0;
	int delta[][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
	srand(time(0));
    do {
        row = rand() % 10;
		col = rand() % 10;
		if (!arr[row][col]) {
			arr[row][col] = -1;
			mines++;
		}
	} while (mines < 10);
	for (row = 0;row <= 9;row++) {
		for (col = 0;col <= 9;col++) {
			if (arr[row][col] == -1) {
				for (num = 0;num <= 7;num++) {
					int newrow = row + delta[num][0];
					int newcol = col + delta[num][1];
					if (newrow < 0 || newrow > 9) {
						continue;
					}
					if (newcol < 0 || newcol > 9) {
						continue;
					}
					if (arr[newrow][newcol] == -1) {
						continue;
					}
					arr[newrow][newcol]++;
				}
			}
		}
	}
	for (row = 0;row <= 9;row++) {
		for (col = 0;col <= 9;col++) {
			if (!arr[row][col]) {
				printf("O");
			}
			else if (arr[row][col] > 0) {
				printf("%d", arr[row][col]);
			}
			else {
				printf("X");
			}
		}
		printf("\n");
	}
	return 0;
}







