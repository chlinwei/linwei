/*
   结构体演示
   */
#include <stdio.h>
typedef struct {
	int row, col;
} pt;
pt *read(pt *p_pt) {
	printf("请输入点的位置：");
	scanf("%d%d", &(p_pt->row), &(p_pt->col));
	return p_pt;
}
void print(const pt *p_pt) {
	printf("(%d, %d)\n", p_pt->row, p_pt->col);
}
int main() {
    pt pt1 = {0}, *p_pt = NULL;
	p_pt = read(&pt1);
	print(&pt1);
	print(p_pt);
	return 0;
}





