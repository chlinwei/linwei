/*
   链式物理结构演示
   */
#include <stdio.h>
typedef struct node {
	int num;
	struct node *p_next;
} node;
int main() {
	node node1 = {1}, node2 = {4}, node3 = {7}, node4 = {5}, head = {0}, tail = {0}, *p_node = NULL;
	int cnt = 0;
	head.p_next = &node1;
	node1.p_next = &node2;
	node2.p_next = &node3;
	node3.p_next = &tail;
	for (p_node = &head;p_node != &tail;p_node = p_node->p_next) {
		node *p_first = p_node;
        node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		if (p_mid != &tail) {
			printf("%d ", p_mid->num);
		}
	}
	printf("\n");
	for (p_node = &head;p_node != &tail;p_node = p_node->p_next) {
		node *p_first = p_node;
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		if (p_mid != &tail) {
			if (cnt == 2) {
				printf("%d\n", p_mid->num);
			}
            cnt++;
		}
	}
	for (p_node = &head;p_node != &tail;p_node = p_node->p_next) {
		node *p_first = p_node;
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		if (p_mid->num > node4.num || p_mid == &tail) {
			p_first->p_next = &node4;
			node4.p_next = p_mid;
			break;
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
	for (p_node = &head;p_node != &tail;p_node = p_node->p_next) {
		node *p_first = p_node;
		node *p_mid = p_first->p_next;
		node *p_last = p_mid->p_next;
		if (p_mid->num == 4) {
			p_first->p_next = p_last;
			break;
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
	return 0;
}







