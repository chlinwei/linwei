/*
   栈实现
   */
#ifndef       __03STACK_H__
#define       __03STACK_H__
typedef struct node {
	int num;
	struct node *p_next;
} node;
typedef struct {
	node head, tail;
} stack;
//栈初始化函数
void stack_init(stack *);
//清理函数
void stack_deinit(stack *);
//判断是否满的函数
int stack_full(const stack *);
//判断是否空的函数
int stack_empty(const stack *);
//向栈里放数字的函数
void stack_push(stack *, int );
//从栈里取出数字的函数
int stack_pop(stack *);
//从栈里获得数字的函数
int stack_top(const stack *);
//获得栈里的数字个数
int stack_size(const stack *);
#endif   //__03STACK_H__






