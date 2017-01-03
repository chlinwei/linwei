/*
   条件编译演示
   */
#include <stdio.h>
int main() {
#ifdef   YI
	printf("1\n");
#else
	printf("2\n");
#endif
	return 0;
}
//gcc 01.c -D=YI
