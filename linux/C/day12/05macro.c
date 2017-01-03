/*
   宏练习
   */
#include <stdio.h>
#define   SUB(x, y)   ((x) - (y))
int main() {
	printf("SUB(10, 6)是%d\n", SUB(10, 6));
	printf("20 - SUB(10, 6)是%d\n", 20 - SUB(10, 6));
	printf("SUB(20, 10 - 6)是%d\n", SUB(20, 10 - 6));
	return 0;
}
