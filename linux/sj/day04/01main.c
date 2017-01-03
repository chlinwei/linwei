/*
   树测试
   */
#include <stdio.h>
#include "01tree.h"
void print_cb(int num) {
	printf("%d ", num);
}
int main() {
	tree tr = {0};
	tree_init(&tr);
	tree_insert_in_order(&tr, 40);
	tree_insert_in_order(&tr, 21);
	tree_insert_in_order(&tr, 27);
	tree_insert_in_order(&tr, 15);
	tree_insert_in_order(&tr, 60);
	tree_insert_in_order(&tr, 58);
	tree_insert_in_order(&tr, 71);
	tree_insert_in_order(&tr, 52);
	tree_remove(&tr, 60);
	//tree_print(&tr);
	miter(&tr, print_cb);
	printf("\n");
	printf("有效数字个数是%d\n", tree_size(&tr));
	printf("高度是%d\n", tree_height(&tr));
	tree_mirror(&tr);
	//tree_print(&tr);
	miter(&tr, print_cb);
	printf("\n");
	tree_deinit(&tr);
	return 0;
}




