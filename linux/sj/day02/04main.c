/*
   队列测试
   */
#include <stdio.h>
#include "04queue.h"
int main() {
	queue que = {};
	queue_init(&que);
	queue_push(&que, 1);
	queue_push(&que, 3);
	queue_push(&que, 5);
	printf("数字个数是%d\n", queue_size(&que));
	printf("%d ", queue_pop(&que));
	printf("%d ", queue_pop(&que));
	printf("%d\n", queue_pop(&que));
	queue_deinit(&que);
	return 0;
}




