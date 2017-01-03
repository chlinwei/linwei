/*
   链表实现
   */
#ifndef    __01LINK_H__
#define    __01LINK_H__
typedef struct node {
	int num;
	struct node *p_next;
	struct node *p_pre;
} node;
typedef struct {
	node head, tail;
	node *p_cur;
} link;
//链表初始化函数
void link_init(link *);
//清理函数
void link_deinit(link *);
//判断是否空的函数
int link_empty(const link *);
//统计有效节点个数
int link_size(const link *);
//把新数字加入到前面
void link_add_head(link *, int );
//把新数字加入到末尾
void link_append(link *, int );
//把新数字按顺序加入
void link_insert_in_order(link *, int );
//获得最前面数字的函数
int link_get_head(const link *);
//获得最后面数字的函数
int link_get_tail(const link *);
//删除第一个数字函数
void link_remove_head(link *);
//删除最后一个数字函数
void link_remove_tail(link *);
//删除某个数字函数
void link_remove(link *, int );
//开始遍历
void link_begin(link *);
//获得下一个数字
int link_next(link *, int *);
#endif   //__01LINK_H__






