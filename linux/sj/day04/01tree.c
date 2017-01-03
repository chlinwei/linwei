/*
   树实现
   */
#include <stdlib.h>
#include "01tree.h"
//初始化函数
void tree_init(tree *p_tree) {
	p_tree->p_root = NULL;
}
//清理函数
void tree_deinit(tree *p_tree) {
	if (!(p_tree->p_root)) {
		return ;
	}
	tree_deinit(&(p_tree->p_root->left));
	tree_deinit(&(p_tree->p_root->right));
	free(p_tree->p_root);
	p_tree->p_root = NULL;
}
//查找数字所在的位置
static tree *tree_search_in_order(tree *p_tree, int num) {
	if (!(p_tree->p_root) || p_tree->p_root->num == num) {
		return p_tree;
	}
	else if (p_tree->p_root->num > num) {
		return tree_search_in_order(&(p_tree->p_root->left), num);
	}
	else {
		return tree_search_in_order(&(p_tree->p_root->right), num);
	}
}
//按顺序插入数字
void tree_insert_in_order(tree *p_tree, int num) {
	tree *p_tmp = tree_search_in_order(p_tree, num);
	if (!(p_tmp->p_root)) {
		node *p_node = (node *)malloc(sizeof(node));
		if (p_node) {
			p_node->num = num;
			p_node->left.p_root = NULL;
			p_node->right.p_root = NULL;
			p_tmp->p_root = p_node;
		}
	}
}
//按顺序把有序二叉树里的数字打印在
//屏幕上
/*void tree_print(tree *p_tree) {
	if (!(p_tree->p_root)) {
		return ;
	}
    tree_print(&(p_tree->p_root->left));
	printf("%d ", p_tree->p_root->num);
	tree_print(&(p_tree->p_root->right));
}*/
//中序遍历函数
void miter(const tree *p_tree, void (*p_func)(int)) {
	if (!(p_tree->p_root)) {
		return ;
	}
	miter(&(p_tree->p_root->left), p_func);
	p_func(p_tree->p_root->num);
	miter(&(p_tree->p_root->right), p_func);
}
//统计有效数字个数
int tree_size(const tree *p_tree) {
	int ret = 0;
	if (!(p_tree->p_root)) {
		return 0;
	}
	ret += tree_size(&(p_tree->p_root->left));
	ret += tree_size(&(p_tree->p_root->right));
	return ret + 1;
}
//统计树的高度
int tree_height(const tree *p_tree) {
	int left_height = 0, right_height = 0;
	if (!(p_tree->p_root)) {
		return 0;
	}
	left_height = tree_height(&(p_tree->p_root->left));
	right_height = tree_height(&(p_tree->p_root->right));
    if (left_height > right_height) {
		return left_height + 1;
	}
	else {
		return right_height + 1;
	}
}
//镜像函数
void tree_mirror(tree *p_tree) {
	if (!(p_tree->p_root)) {
		return ;
	}
	node *p_tmp = p_tree->p_root->left.p_root;
	p_tree->p_root->left.p_root = p_tree->p_root->right.p_root;
	p_tree->p_root->right.p_root = p_tmp;
	tree_mirror(&(p_tree->p_root->left));
	tree_mirror(&(p_tree->p_root->right));
}
//删除数字函数
void tree_remove(tree *p_tree, int num) {
	node *p_root = NULL, *p_left = NULL, *p_right = NULL;
	tree *p_tmp = tree_search_in_order(p_tree, num);
	if (!(p_tmp->p_root)) {
		return ;
	}
	p_root = p_tmp->p_root;
	p_left = p_root->left.p_root;
	p_right = p_root->right.p_root;
	if (!p_left) {
		p_tmp->p_root = p_right;
	}
	else if (!p_right) {
		p_tmp->p_root = p_left;
	}
	else {
		tree *p_tmp1 = tree_search_in_order(&(p_tmp->p_root->left), p_right->num);
		p_tmp1->p_root = p_right;
		p_tmp->p_root = p_left;
	}
	free(p_root);
	p_root = NULL;
}










