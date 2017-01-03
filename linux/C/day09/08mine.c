/*
   布雷练习
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void plant(int map[][10], int size, int mines) {
	int row = 0, col = 0, cnt = 0;
	do {
		row = rand() % size;
		col = rand() % 10;
		if (!map[row][col]) {
			map[row][col] = -1;
			cnt++;
		}
	} while (cnt < mines);
}
void print(int map[][10], int size) {
	int row = 0, col = 0;
	for (row = 0;row <= size - 1;row++) {
		for (col = 0;col <= 9;col++) {
			if (map[row][col] == -1) {
			    printf("X");
			}
			else {
				printf("O");
			}
		}
		printf("\n");
	}
}
int main() {
	int arr[10][10] = {0};
	srand(time(0));
	plant(arr, 10, 10);
	print(arr, 10);
	return 0;
}


