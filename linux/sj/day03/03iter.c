/*
   遍历功能测试
   */
#include <stdio.h>
#include "01link.h"
int main() {
	int num = 0;
	link lk = {0};
	link_init(&lk);
	link_insert_in_order(&lk, 6);
	link_insert_in_order(&lk, 3);
	link_insert_in_order(&lk, 54);
	link_insert_in_order(&lk, 38);
	link_insert_in_order(&lk, 21);
	link_insert_in_order(&lk, 63);
	link_begin(&lk);
	while (1) {
		if (!link_next(&lk, &num)) {
			break;
		}
		printf("%d ", num);
	}
	printf("\n");
	link_deinit(&lk);
	return 0;
}



