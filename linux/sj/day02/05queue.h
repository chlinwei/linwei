/*
   队列实现
   */
#ifndef    __05QUEUE_H__
#define    __05QUEUE_H__
typedef struct node {
	int num;
	struct node *p_next;
} node;
typedef struct {
	node head, tail;
} queue;
//初始化函数
void queue_init(queue *);
//清理函数
void queue_deinit(queue *);
//判断队列是否满的函数
int queue_full(const queue *);
//判断队列是否空的函数
int queue_empty(const queue *);
//向队列里放数字的函数
void queue_push(queue *, int);
//从队列里取出一个数字
int queue_pop(queue *);
//从队列里获得下一个数字
int queue_front(queue *);
//统计队列里的数字个数
int queue_size(const queue *); 
#endif   //__05QUEUE_H__






