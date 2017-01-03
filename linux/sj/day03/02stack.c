/*
   栈实现
   */
#include "01link.h"
#include "02stack.h"
//栈初始化函数
void stack_init(stack *p_stack) {
	link_init(&(p_stack->lk));
}
//清理函数
void stack_deinit(stack *p_stack) {
	link_deinit(&(p_stack->lk));
}
//判断是否满的函数
int stack_full(const stack *p_stack) {
	return 0;
}
//判断是否空的函数
int stack_empty(const stack *p_stack) {
	return link_empty(&(p_stack->lk));
}
//向栈里放数字的函数
void stack_push(stack *p_stack, int num) {
	link_append(&(p_stack->lk), num);
}
//从栈里取出数字的函数
int stack_pop(stack *p_stack) {
	int ret = link_get_tail(&(p_stack->lk));
	link_remove_tail(&(p_stack->lk));
	return ret;
}
//从栈里获得数字的函数
int stack_top(const stack *p_stack) {
	return link_get_tail(&(p_stack->lk));
}
//获得栈里的数字个数
int stack_size(const stack *p_stack) {
	return link_size(&(p_stack->lk));
}






