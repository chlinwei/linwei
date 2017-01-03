/*
   fscanf函数演示
   */
#include <stdio.h>
int main() {
	int arr[5] = {0}, num = 0;
	FILE *p_file = fopen("a.txt", "r");
	if (p_file) {
		fscanf(p_file, "%d%d%d%d%d", arr, arr + 1, arr + 2, arr + 3, arr + 4);
		for (num = 0;num <= 4;num++) {
			printf("%d ", arr[num]);
		}
		printf("\n");
		fclose(p_file);
		p_file = NULL;
	}
	return 0;
}
