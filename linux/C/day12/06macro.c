/*
   宏练习
   */
#include <stdio.h>
#define SQUARE(x)     ((x) * (x))
int main() {
	int num = 5;
    printf("SQUARE(5)是%d\n", SQUARE(5));
	printf("100 / SQUARE(5)是%d\n", 100 / SQUARE(5));
	printf("SQUARE(2 + 3)是%d\n", SQUARE(2 + 3));
	printf("SQUARE(++num)是%d\n", SQUARE(++num));
	return 0;
}


