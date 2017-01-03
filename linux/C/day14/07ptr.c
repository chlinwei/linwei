/*
   二级指针练习
   */
#include <stdio.h>
typedef struct {
	int row, col;
} pt;
typedef struct {
	pt center;
	int radius;
} circle;
void larger(const circle *p_cl1, const circle *p_cl2, circle **pp_cl) {
	*pp_cl = (circle *)(p_cl1->radius > p_cl2->radius ? p_cl1 : p_cl2);
}
int main() {
	circle cl1 = {0}, cl2 = {0}, *p_circle = NULL;
	printf("请输入一个圆的位置：");
	scanf("%d%d%d", &(cl1.center.row), &(cl1.center.col), &(cl1.radius));
	printf("请再次输入一个圆的位置：");
	scanf("%d%d%d", &(cl2.center.row), &(cl2.center.col), &(cl2.radius));
	larger(&cl1, &cl2, &p_circle);
	printf("位置是((%d, %d), %d)\n", p_circle->center.row, p_circle->center.col, p_circle->radius);
	return 0;
}





