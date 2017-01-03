/*
   折半查找练习
   */
#include <stdio.h>
/*int *half_search(int *p_num, int size, int num) {
	int *p_start = p_num, *p_end = p_num + size - 1;
	while (p_start <= p_end) {
		int *p_mid = p_start + (p_end - p_start) / 2;
		if (*p_mid == num) {
			return p_mid;
		}
		else if (*p_mid > num) {
			p_end = p_mid - 1;
		}
		else {
			p_start = p_mid + 1;
		}
	}
	return NULL;
}*/
int *half_search(int *p_num, int size, int num) {
	int pos = size / 2;
	if (size <= 0) {
		return NULL;
	}
	if (*(p_num + pos) == num) {
		return p_num + pos;
	}
	else if (*(p_num + pos) > num) {
		return half_search(p_num, pos, num);
	}
	else {
		return half_search(p_num + pos + 1, size - pos - 1, num);
	}
}
int main() {
	int arr[] = {23, 41, 50, 61, 77, 81, 92};
	int *p_num = half_search(arr, 7, 55);
	if (p_num) {
	    printf("%d\n", *p_num);
	}
	else {
		printf("没有找到\n");
	}
	return 0;
}


