/*
   链式结构练习
   */
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int num;
	struct node *p_next;
} node;
int main() {
    int num = 0;
	node head = {0}, tail = {0}, *p_node = NULL, *p_node1 = NULL;
	head.p_next = &tail;
	while (1) {
		printf("请输入一个数字：");
		scanf("%d", &num);
		if (num < 0) {
			break;
		}
        p_node = (node *)malloc(sizeof(node));
		if (!p_node) {
			break;
		}
		p_node->num = num;
		p_node->p_next = NULL;
		for (p_node1 = &head;p_node1 != &tail;p_node1 = p_node1->p_next) {
			node *p_first = p_node1;
			node *p_mid = p_first->p_next;
			node *p_last = p_mid->p_next;
			if (p_mid == &tail || p_mid->num > p_node->num) {
				p_first->p_next = p_node;
				p_node->p_next = p_mid;
				break;
			}
		}
	}
	for (p_node = &head;p_node != &tail;p_node = p_node->p_next) {
		node *p_first = p_node;
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		if (p_mid != &tail) {
			printf("%d ", p_mid->num);
		}
	}
	printf("\n");
	while (head.p_next != &tail) {
		node *p_first = &head;
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		p_first->p_next = p_last;
		free(p_mid);
		p_mid = NULL;
	}
	return 0;
}








