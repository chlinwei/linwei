/*
   队列实现
   */
#ifndef    __04QUEUE_H__
#define    __04QUEUE_H__
typedef struct {
	int buf[SIZE];
	//如果队列里有数字则head表示第一个
	//数字所在的下标，如果没有数字
	//则head和tail一样
	//tail表示最后一个数字所在下标
	//的后一个下标
	int head, tail;
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
int queue_size(const queue *p_queue); 
#endif   //__04QUEUE_H__






