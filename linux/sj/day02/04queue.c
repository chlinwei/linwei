/*
   队列实现
   */
#include "04queue.h"
//初始化函数
void queue_init(queue *p_queue) {
	p_queue->head = 0;
	p_queue->tail = 0;
}
//清理函数
void queue_deinit(queue *p_queue) {
	p_queue->head = 0;
	p_queue->tail = 0;
}
//判断队列是否满的函数
int queue_full(const queue *p_queue) {
	return p_queue->tail == SIZE;
}
//判断队列是否空的函数
int queue_empty(const queue *p_queue) {
	return p_queue->head == p_queue->tail;
}
//向队列里放数字的函数
void queue_push(queue *p_queue, int num) {
	p_queue->buf[p_queue->tail] = num;
	p_queue->tail++;
}
//从队列里取出一个数字
int queue_pop(queue *p_queue) {
	p_queue->head++;
	return p_queue->buf[p_queue->head - 1];
}
//从队列里获得下一个数字
int queue_front(queue *p_queue) {
	return p_queue->buf[p_queue->head];
}
//统计队列里的数字个数
int queue_size(const queue *p_queue) {
	return p_queue->tail - p_queue->head;
}







