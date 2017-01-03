#include <stdio.h>

int main(void)
{
	int* pi = (int*)0xbfa36e0c;
	printf("*pi = %d\n",*pi); // 66
	return 0;
}
