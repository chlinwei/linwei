/*
   栈实现
   */
#include "03stack.h"
#include <stdlib.h>
//栈初始化函数
void stack_init(stack *p_stack) {
	p_stack->head.p_next = &(p_stack->tail);
}
//清理函数
void stack_deinit(stack *p_stack) {
	while (p_stack->head.p_next != &(p_stack->tail)) {
		node *p_first = &(p_stack->head);
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		p_first->p_next = p_last;
		free(p_mid);
		p_mid = NULL;
	}
}
//判断是否满的函数
int stack_full(const stack *p_stack) {
	return 0;
}
//判断是否空的函数
int stack_empty(const stack *p_stack) {
	return p_stack->head.p_next == &(p_stack->tail);
}
//向栈里放数字的函数
void stack_push(stack *p_stack, int num) {
    node *p_node = (node *)malloc(sizeof(node));
	if (p_node) {
		node *p_first = &(p_stack->head);
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		p_first->p_next = p_node;
		p_node->p_next = p_mid;
		p_node->num = num;
	}
}
//从栈里取出数字的函数
int stack_pop(stack *p_stack) {
	int ret = 0;
	node *p_first = &(p_stack->head);
	node *p_mid = p_first->p_next;
	node *p_last = p_mid->p_next;
	p_first->p_next = p_last;
	ret = p_mid->num;
	free(p_mid);
	p_mid = NULL;
	return ret;
}
//从栈里获得数字的函数
int stack_top(const stack *p_stack) {
	return p_stack->head.p_next->num;
}
//获得栈里的数字个数
int stack_size(const stack *p_stack) {
	int cnt = 0;
	const node *p_node = NULL;
	for (p_node = &(p_stack->head);p_node != &(p_stack->tail);p_node = p_node->p_next) {
		const node *p_first = p_node;
		const node *p_mid = p_first->p_next;
		const node *p_last = p_mid->p_next;
		if (p_mid != &(p_stack->tail)) {
			cnt++;
		}
	}
	return cnt;
}











