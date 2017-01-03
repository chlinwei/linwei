/*
   栈测试
   */
#include <stdio.h>
#include "02stack.h"
int main() {
	stack stk = {};
	stack_init(&stk);
	stack_push(&stk, 1);
	stack_push(&stk, 3);
	stack_push(&stk, 5);
	printf("有效数据个数是%d\n", stack_size(&stk));
	printf("%d ", stack_pop(&stk));
	printf("%d ", stack_pop(&stk));
	printf("%d\n", stack_pop(&stk));
	stack_deinit(&stk);
	return 0;
}





