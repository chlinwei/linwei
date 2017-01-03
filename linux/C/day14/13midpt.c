/*
   动态分配内存练习
   */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int row, col;
} pt;
pt *midpt(const pt *p_pt1, const pt *p_pt2) {
	pt *p_pt = (pt *)malloc(sizeof(pt));
	if (p_pt) {
		p_pt->row = (p_pt1->row + p_pt2->row) / 2;
		p_pt->col = (p_pt1->col + p_pt2->col) / 2;
	}
	return p_pt;
}
int main() {
	pt pt1 = {0}, pt2 = {0}, *p_pt = NULL;
	printf("请输入一个点的位置：");
	scanf("%d%d", &(pt1.row), &(pt1.col));
	printf("请再次输入一个点的位置：");
	scanf("%d%d", &(pt2.row), &(pt2.col));
	p_pt = midpt(&pt1, &pt2);
	if (p_pt) {
		printf("中间点位置是(%d, %d)\n", p_pt->row, p_pt->col);
		free(p_pt);
		p_pt = NULL;
	}
	return 0;
}





