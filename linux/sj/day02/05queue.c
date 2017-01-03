/*
   队列实现
   */
#include <stdlib.h>
#include "05queue.h"
void queue_init(queue *p_queue) {
	p_queue->head.p_next = &(p_queue->tail);
}
//清理函数
void queue_deinit(queue *p_queue) {
	while (p_queue->head.p_next != &(p_queue->tail)) {
		node *p_first = &(p_queue->head);
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		p_first->p_next = p_last;
		free(p_mid);
		p_mid = NULL;
	}
}
//判断队列是否满的函数
int queue_full(const queue *p_queue) {
	return 0;
}
//判断队列是否空的函数
int queue_empty(const queue *p_queue) {
	return p_queue->head.p_next == &(p_queue->tail);
}
//向队列里放数字的函数
void queue_push(queue *p_queue, int num) {
	node *p_node = (node *)malloc(sizeof(node));
	if (p_node) {
		node *p_first = &(p_queue->head);
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		p_first->p_next = p_node;
		p_node->p_next = p_mid;
		p_node->num = num;
	}
}
//从队列里取出一个数字
int queue_pop(queue *p_queue) {
	node *p_node = NULL;
	for (p_node = &(p_queue->head);p_node != &(p_queue->tail);p_node = p_node->p_next) {
		node *p_first = p_node;
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		if (p_last == &(p_queue->tail)) {
			int ret = p_mid->num;
			p_first->p_next = p_last;
			free(p_mid);
			p_mid = NULL;
			return ret;
		}
	}
}
//从队列里获得下一个数字
int queue_front(queue *p_queue) {
	node *p_node = NULL;
	for (p_node = &(p_queue->head);p_node != &(p_queue->tail);p_node = p_node->p_next) {
		node *p_first = p_node;
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		if (p_last == &(p_queue->tail)) {
			return p_mid->num;
		}
	}
}
//统计队列里的数字个数
int queue_size(const queue *p_queue) {
	int cnt = 0;
	const node *p_node = NULL;
	for (p_node = &(p_queue->head);p_node != &(p_queue->tail);p_node = p_node->p_next) {
		const node *p_first = p_node;
		const node *p_mid = p_first->p_next;
		const node *p_last = p_mid->p_next;
		if (p_mid != &(p_queue->tail)) {
			cnt++;
		}
	}
	return cnt;
}







