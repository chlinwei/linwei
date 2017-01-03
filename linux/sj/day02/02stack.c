/*
   栈实现
   */
#include "02stack.h"
//栈初始化函数
void stack_init(stack *p_stack) {
    p_stack->num = 0;
}
//清理函数
void stack_deinit(stack *p_stack) {
	p_stack->num = 0;
}
//判断是否满的函数
int stack_full(const stack *p_stack) {
	return p_stack->num == SIZE;
}
//判断是否空的函数
int stack_empty(const stack *p_stack) {
	return !p_stack->num;
}
//向栈里放数字的函数
void stack_push(stack *p_stack, int num) {
	p_stack->buf[p_stack->num] = num;
	p_stack->num++;
}
//从栈里取出数字的函数
int stack_pop(stack *p_stack) {
	int ret = p_stack->buf[p_stack->num - 1];
	p_stack->num--;
	return ret;
}
//从栈里获得数字的函数
int stack_top(const stack *p_stack) {
	return p_stack->buf[p_stack->num - 1];
}
//获得栈里的数字个数
int stack_size(const stack *p_stack) {
	return p_stack->num;
}







