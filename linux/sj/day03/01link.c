/*
   链表实现
   */
#include <stdlib.h>
#include "01link.h"
//链表初始化函数
void link_init(link *p_link) {
	p_link->head.p_next = &(p_link->tail);
	p_link->tail.p_pre = &(p_link->head);
	p_link->tail.p_next = NULL;
	p_link->head.p_pre = NULL;
	p_link->p_cur = NULL;
}
//清理函数
void link_deinit(link *p_link) {
	while (p_link->head.p_next != &(p_link->tail)) {
		node *p_first = &(p_link->head);
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		p_first->p_next = p_last;
		p_last->p_pre = p_first;
		free(p_mid);
		p_mid = NULL;
	}
	p_link->p_cur = NULL;
}
//判断是否空的函数
int link_empty(const link *p_link) {
	return p_link->head.p_next == &(p_link->tail);
}
//统计有效节点个数
int link_size(const link *p_link) {
	int cnt = 0;
	const node *p_node = NULL;
	for (p_node = &(p_link->head);p_node != &(p_link->tail);p_node = p_node->p_next) {
		const node *p_first = p_node;
		const node *p_mid = p_first->p_next;
		const node *p_last = p_mid->p_next;
		if (p_mid != &(p_link->tail)) {
			cnt++;
		}
	}
	return cnt;
}
//把新数字加入到前面
void link_add_head(link *p_link, int num) {
     node *p_node = (node *)malloc(sizeof(node));
	 if (p_node) {
		 node *p_first = &(p_link->head);
		 node *p_mid = p_first->p_next;
		 node *p_last = p_mid->p_next;
		 p_first->p_next = p_node;
		 p_node->p_pre = p_first;
		 p_node->p_next = p_mid;
		 p_mid->p_pre = p_node;
		 p_node->num = num;
	 }
}
//把新数字加入到末尾
/*void link_append(link *p_link, int num) {
	node *p_tmp = NULL;
	node *p_node = (node *)malloc(sizeof(node));
	if (!p_node){
		return ;
	}
	p_node->num = num;
	for (p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next) {
		node *p_first = p_tmp;
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		if (p_mid == &(p_link->tail)) {
			p_first->p_next = p_node;
			p_node->p_pre = p_first;
			p_node->p_next = p_mid;
			p_mid->p_pre = p_node;
			break;
		}
	}
}*/
void link_append(link *p_link, int num) {
	node *p_node = (node *)malloc(sizeof(node));
	if (!p_node) {
		return ;
	}
	node *p_first = p_link->tail.p_pre;
	node *p_mid = p_first->p_next;
	node *p_last = p_mid->p_next;
	p_first->p_next = p_node;
	p_node->p_pre = p_first;
	p_node->p_next = p_mid;
	p_mid->p_pre = p_node;
	p_node->num = num;
}
//把新数字按顺序加入
void link_insert_in_order(link *p_link, int num) {
	node *p_tmp = NULL;
	node *p_node = (node *)malloc(sizeof(node));
	if (!p_node) {
		return ;
	}
	p_node->num = num;
	for (p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next) {
		node *p_first = p_tmp;
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		if (p_mid->num > p_node->num || p_mid == &(p_link->tail)) {
			p_first->p_next = p_node;
			p_node->p_pre = p_first;
			p_node->p_next = p_mid;
			p_mid->p_pre = p_node;
			break;
		}
	}
}
//获得最前面数字的函数
int link_get_head(const link *p_link) {
	return p_link->head.p_next->num;
}
//获得最后面数字的函数
/*int link_get_tail(const link *p_link) {
	const node *p_node = NULL;
	for (p_node = &(p_link->head);p_node != &(p_link->tail);p_node = p_node->p_next) {
		const node *p_first = p_node;
		const node *p_mid = p_first->p_next;
		const node *p_last = p_mid->p_next;
		if (p_mid == &(p_link->tail)) {
			return p_first->num;
		}
	}
}*/
int link_get_tail(const link *p_link) {
	return p_link->tail.p_pre->num;
}
//删除第一个数字函数
void link_remove_head(link *p_link) {
	node *p_first = &(p_link->head);
	node *p_mid = p_first->p_next;
	node *p_last = p_mid->p_next;
	p_first->p_next = p_last;
	p_last->p_pre = p_first;
	free(p_mid);
	p_mid = NULL;
	p_link->p_cur = NULL;
}
//删除最后一个数字函数
/*void link_remove_tail(link *p_link) {
	node *p_node = NULL;
	for (p_node = &(p_link->head);p_node != &(p_link->tail);p_node = p_node->p_next) {
		node *p_first = p_node;
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		if (p_last == &(p_link->tail)) {
			p_first->p_next = p_last;
			p_last->p_pre = p_first;
			free(p_mid);
			p_mid = NULL;
			break;
		}
	}
}*/
void link_remove_tail(link *p_link) {
	node *p_first = p_link->tail.p_pre->p_pre;
	node *p_mid = p_first->p_next;
	node *p_last = p_mid->p_next;
	p_first->p_next = p_last;
	p_last->p_pre = p_first;
	free(p_mid);
	p_mid = NULL;
	p_link->p_cur = NULL;
}
//删除某个数字函数
void link_remove(link *p_link, int num) {
	node *p_node = NULL;
	for (p_node = &(p_link->head);p_node != &(p_link->tail);p_node = p_node->p_next) {
		node *p_first = p_node;
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		if (p_mid->num == num) {
			p_first->p_next = p_last;
			p_last->p_pre = p_first;
			free(p_mid);
			p_mid = NULL;
			break;
		}
	}
	p_link->p_cur = NULL;
}
//开始遍历
void link_begin(link *p_link) {
	p_link->p_cur = &(p_link->head);
}
//获得下一个数字
int link_next(link *p_link, int *p_num) {
	if (!p_link->p_cur) {
		return 0;
	}
	p_link->p_cur = p_link->p_cur->p_next;
	if (p_link->p_cur == &(p_link->tail)) {
		p_link->p_cur = NULL;
		return 0;
	}
	*p_num = p_link->p_cur->num;
	return 1;
}









