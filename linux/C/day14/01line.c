/*
   结构体作业
   */
#include <stdio.h>
typedef struct {
	int row, col;
} pt;
typedef struct {
	pt pt1, pt2;
} line;
int len2(const line *p_line) {
	return (p_line->pt1.row - p_line->pt2.row) * (p_line->pt1.row - p_line->pt2.row) + (p_line->pt1.col - p_line->pt2.col) * (p_line->pt1.col - p_line->pt2.col);
}
const line *longer(const line *p_l1, const line *p_l2) {
    return len2(p_l1) > len2(p_l2) ? p_l1 : p_l2;
}
int main() {
	line ln1 = {0}, ln2 = {0};
	const line *p_line = NULL;
	printf("请输入一条线段的位置：");
	scanf("%d%d%d%d", &(ln1.pt1.row), &(ln1.pt1.col), &(ln1.pt2.row), &(ln1.pt2.col));
	printf("请再次输入一条线段的位置：");
	scanf("%d%d%d%d", &(ln2.pt1.row), &(ln2.pt1.col), &(ln2.pt2.row), &(ln2.pt2.col));
	p_line = longer(&ln1, &ln2);
	printf("线段位置是((%d, %d), (%d, %d))\n", p_line->pt1.row, p_line->pt1.col, p_line->pt2.row, p_line->pt2.col);
	return 0;
}







