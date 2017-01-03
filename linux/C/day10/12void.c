/*
   void指针演示
   */
#include <stdio.h>
void print(void *p_v, int type) {
	if (type == 0) {
		printf("%c\n", *(char *)p_v);
	}
	else if (type == 1) {
		printf("%d\n", *(int *)p_v);
	}
	else {
		printf("%g\n", *(float *)p_v);
	}
}
int main() {
	char ch = 't';
	int num = 20;
	float fnum = 4.2f;
	print(&ch, 0);
	print(&num, 1);
	print(&fnum, 2);
	return 0;
}
