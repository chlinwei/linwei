/*
   树实现
   */
#ifndef     __01TREE_H__
#define     __01TREE_H__
struct node;
typedef struct {
	struct node *p_root;
} tree;
typedef struct node {
	int num;
	tree left;
	tree right;
} node;
//初始化函数
void tree_init(tree *);
//清理函数
void tree_deinit(tree *);
//按顺序插入数字
void tree_insert_in_order(tree *, int);
//按顺序把有序二叉树里的数字打印在
//屏幕上
//void tree_print(tree *);
//中序遍历函数
void miter(const tree *, void (*)(int));
//统计有效数字个数
int tree_size(const tree *);
//统计树的高度
int tree_height(const tree *);
//镜像函数
void tree_mirror(tree *);
//删除数字函数
void tree_remove(tree *, int);
#endif   //__01TREE_H__









