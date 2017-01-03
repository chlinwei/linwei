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
int area(const rect *p_rect) {
	int res = (p_rect->pt1.row - p_rect->pt2.row) * (p_rect->pt1.col - p_rect->pt2.col);
	return res >= 0 ? res : 0 - res;
}
int main() {
    rect r1 = {0};
	printf("请输入水平长方形的位置：");
	scanf("%d%d%d%d", &(r1.pt1.row), &(r1.pt1.col), &(r1.pt2.row), &(r1.pt2.col));
	printf("面积是%d\n", area(&r1));
	return 0;
}





