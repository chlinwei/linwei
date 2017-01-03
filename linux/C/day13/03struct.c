/*
   结构体练习
   */
#include <stdio.h>
typedef struct {
	int row, col;
} pt;
typedef struct {
	pt pt1, pt2;
} rect;
int main() {
	int area = 0;
	rect r1 = {0}, *p_rect = &r1;
	/*printf("请输入水平长方形的位置：");
	scanf("%d%d%d%d", &(r1.pt1.row), &(r1.pt1.col), &(r1.pt2.row), &(r1.pt2.col));
	area = (r1.pt1.row - r1.pt2.row) * (r1.pt1.col - r1.pt2.col);
	area = area >= 0 ? area : 0 - area;
	printf("面积是%d\n", area);*/
	printf("请输入水平长方形的位置：");
	scanf("%d%d%d%d", &(p_rect->pt1.row), &(p_rect->pt1.col), &(p_rect->pt2.row), &(p_rect->pt2.col));
	area = (p_rect->pt1.row - p_rect->pt2.row) * (p_rect->pt1.col - p_rect->pt2.col);
	area = area >= 0 ? area : 0 - area;
	printf("面积是%d\n", area);
	return 0;
}








