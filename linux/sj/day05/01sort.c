/*
   排序算法演示
   */
#include <stdio.h>
//快速排序
void quick_sort(int *p_start, int *p_end) {
	int *p_head = p_start;
	int *p_tail = p_end;
	int base = *p_head;
	if (p_start >= p_end) {
		return ;
	}
	while (p_head < p_tail) {
		if (*p_head > *p_tail) {
			int tmp = *p_head;
			*p_head = *p_tail;
			*p_tail = tmp;
		}
		if (*p_head == base) {
			p_tail--;
		}
		else {
			p_head++;
		}
	}
	quick_sort(p_start, p_head - 1);
	quick_sort(p_tail + 1, p_end);
}
//插入排序
void insert_sort(int *p_num, int size) {
	int num = 0, num1 = 0;
	for (num = 1;num <= size - 1;num++) {
        for (num1 = num - 1;num1 >= 0;num1--) {
			if (*(p_num + num1) > *(p_num + num1 + 1)) {
				int tmp = *(p_num + num1);
				*(p_num + num1) = *(p_num + num1 + 1);
				*(p_num + num1 + 1) = tmp;
			}
			else {
				break;
			}
		}
	}
}
//选择排序函数
void choice_sort(int *p_num, int size) {
	int num = 0, num1 = 0;
	for (num = 0;num <= size - 2;num++) {
        for (num1 = num + 1;num1 <= size - 1; num1++) {
            if (*(p_num + num) > *(p_num + num1)) {
				int tmp = *(p_num + num);
				*(p_num + num) = *(p_num + num1);
				*(p_num + num1) = tmp;
			}
		}
	}
}
//冒泡排序函数
void bubble_sort(int *p_num, int size) {
	int num = 0, num1 = 0;
	for (num = size - 1;num >= 1;num--) {
		for (num1 = 0;num1 <= num - 1;num1++) {
			if (*(p_num + num1) > *(p_num + num1 + 1)) {
				int tmp = *(p_num + num1);
				*(p_num + num1) = *(p_num + num1 + 1);
				*(p_num + num1 + 1) = tmp;
			}
		}
	}
}
int main() {
	int arr[] = {50, 23, 86, 12, 36, 41, 73}, num = 0;
    //bubble_sort(arr, 7);
	//choice_sort(arr, 7);
	//insert_sort(arr, 7);
	quick_sort(arr, arr + 6);
	for (num = 0;num <= 6;num++) {
		printf("%d ", arr[num]);
	}
	printf("\n");
	return 0;
}





