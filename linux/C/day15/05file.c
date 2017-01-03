/*
   文件操作练习
   */
#include <stdio.h>
#include <string.h>
int main() {
	int arr[] = {1, 2, 3, 4, 5}, num = 0;
	char str[20] = {0};
	char tmp[10] = {0};
	FILE *p_file = NULL;
	for (num = 0;num <= 4;num++) {
		sprintf(tmp, "%d ", arr[num]);
		strcat(str, tmp);
	}
	p_file = fopen("a.txt", "wb");
	if (p_file) {
		fwrite(str, sizeof(char), strlen(str), p_file);
		fclose(p_file);
		p_file = NULL;
	}
	return 0;
}







